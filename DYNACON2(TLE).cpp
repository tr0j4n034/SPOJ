//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/16/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <utility>
#include <cassert>

using namespace std;

const int S = 100005;
const int BLOCK_SIZE = 321;

struct query{
    int type; // 1 - add/ 2 - delete / 3 - ask
    int a;
    int b;
    query() {}
    query(int type, int a, int b):type(type), a(a), b(b) {}
};

int N, Q;
query q[S];
int nextQuery[S], nextNonQuery[S];
int prevQuery[S], prevNonQuery[S];
vector<set<int>> graph;

int parent[S], size[S];
int virtualParent[S], virtualSize[S];
int mutated[S]; int mtsize = 0; // mutated elements
int counters[S]; // change counts for edges
int nextChanges[S]; // next changes for edges
int prevChanges[S]; // previous changes for edges
int results[S];

int getParent(int a, bool track = false) {
    if (a == parent[a]) return a;
    else {
        int p = getParent(parent[a]);
        if (track) {
            mutated[mtsize ++] = a;
        }
        return parent[a] = p;
    }
}
void Union(int a, int b, bool track = false) {
    int roota = getParent(a, track);
    int rootb = getParent(b, track);
    if (roota == rootb) return;
    if (size[roota] < size[rootb]) swap(roota, rootb);
    parent[rootb] = roota;
    size[roota] += size[rootb];
    if (track) {
        mutated[mtsize ++] = rootb;
    }
}
void buildDSU(vector<set<int>> &graph, int qlow, int qhigh) { // build DSU before [qlow, qhigh] queries
    for (int i = 0; i <= qhigh - qlow + 1; i ++) {
        counters[i] = 0;
        nextChanges[i] = qhigh + 1;
        prevChanges[i] = -1;
    }
    map<pair<int, int>, int> was;
    for (int i = nextNonQuery[qlow - 1]; i <= qhigh; i = nextNonQuery[i]) {
        //if (q[i].type == 3) continue;
        if (q[i].type == 1) counters[i] = 1;
        else counters[i] = -1;
        if (was.count(make_pair(q[i].a, q[i].b))) {
            int j = was[make_pair(q[i].a, q[i].b)];
            nextChanges[j] = i;
            prevChanges[i] = j;
            counters[i] += counters[j];
        }
        was[make_pair(q[i].a, q[i].b)] = i;
        if (counters[i] < 0) {
            if (graph[q[i].a].count(q[i].b)) {
                graph[q[i].a].erase(q[i].b);
            }
        }
    }
    for (int i = 1; i <= N; i ++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= N; i ++) {
        for (int neighbor: graph[i]) {
            Union(i, neighbor);
        }
    }
    for (int i = 1; i <= N; i ++) {
        virtualParent[i] = parent[i];
        virtualSize[i] = size[i];
    }
}
void updateGraph(vector<set<int>> &graph, int qlow, int qhigh) { // updating graph after [qlow, qhigh] queries
    for (int i = qlow; i <= qhigh; i ++) {
        if (q[i].type == 1) {
            graph[q[i].a].insert(q[i].b);
        }
        else if (q[i].type == 2 && graph[q[i].a].count(q[i].b)) {
            graph[q[i].a].erase(q[i].b);
        }
    }
}
void rollbackMutations() {
    for (int it = 0; it < mtsize; it ++) {
        int i = mutated[it];
        parent[i] = virtualParent[i];
        size[i] = virtualSize[i];
    }
    mtsize = 0;
}

template <class T>
void fastInput(T &N) {
    char ch;
    int sign = 1;
    N = 0;
    while ((ch = getchar_unlocked()) && ch == ' ') {};
    if (ch == '-') sign = -1;
    else if (isdigit(ch)) N = ch - '0';
    while ((ch = getchar_unlocked()) && isdigit(ch)) {
        N = (N << 1) + (N << 3) + ch - '0';
    }
    if (sign == -1) N = ~N + 1;
}

int main() {
    //scanf("%d%d", &N, &Q);
    fastInput(N);
    fastInput(Q);
    for (int i = 1; i <= Q; i ++) {
        char s[10];
        //scanf("%s%d%d", s, &q[i].a, &q[i].b);
        scanf("%s", s);
        fastInput(q[i].a);
        fastInput(q[i].b);
        if (q[i].a > q[i].b) swap(q[i].a, q[i].b);
        if (s[0] == 'a') q[i].type = 1;
        else if (s[0] == 'r') q[i].type = 2;
        else q[i].type = 3;
    }
    for (int i = Q; i >= 0; i --) {
        if (i == Q) {
            nextQuery[i] = Q + 1;
            nextNonQuery[i] = Q + 1;
        }
        else {
            if (q[i + 1].type == 3) {
                nextQuery[i] = i + 1;
                nextNonQuery[i] = nextNonQuery[i + 1];
            } else {
                nextQuery[i] = nextQuery[i + 1];
                nextNonQuery[i] = i + 1;
            }
        }
    }
    for (int i = 1; i <= Q + 1; i ++) {
        if (i == 1) {
            prevQuery[i] = 0;
            prevNonQuery[i] = 0;
        }
        else {
            if (q[i - 1].type == 3) {
                prevQuery[i] = i - 1;
                prevNonQuery[i] = prevNonQuery[i - 1];
            }
            else {
                prevQuery[i] = prevQuery[i - 1];
                prevNonQuery[i] = i - 1;
            }
        }
    }
    graph.resize(N + 1);
    for (int i = 1; i <= Q; i += BLOCK_SIZE) {
        int qlow = i;
        int qhigh = min(Q, i + BLOCK_SIZE - 1);
        buildDSU(graph, qlow, qhigh);
        for (int j = prevQuery[qhigh + 1]; j >= qlow; j = prevQuery[j]) {
            //if (q[j].type != 3) continue;
            for (int k = qlow; k <= qhigh; k = nextNonQuery[k]) {
                //if (q[k].type == 3) continue;
                if (nextChanges[k] < j) continue;
                if (k < j && counters[k] > 0) {
                    Union(q[k].a, q[k].b, false);
                }
                if (k > j && prevChanges[k] == -1 && counters[k] < 0) {
                    Union(q[k].a, q[k].b, true);
                }
            }
            int pa = getParent(q[i].a, true);
            int pb = getParent(q[i].b, true);
            if (pa == pb) results[j] = +1;
            else results[j] = -1;
            rollbackMutations();
        }
        updateGraph(graph, qlow, qhigh);
    }
    for (int i = 1; i <= Q; i ++) {
        if (results[i] == +1) puts("YES");
        else if (results[i] == -1) puts("NO");
    }
    
    return 0;
}
