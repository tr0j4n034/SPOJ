//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/10/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 O(Q * sqrt(Q) * log(N)) solution by sqrt decomposition
 Fast Input and caching LCA queries are used to reduce execution time
 Note: The problem can be solved in O(Q * log^2(N)) by HLD
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <ctime>

using namespace std;

const int MAGIC = 333;
const int MAX = 100005;
const int MAX_DEPTH = 18;

int N, Q;
int x[MAX], y[MAX];
int parent[MAX][MAX_DEPTH], depth[MAX];
int selfCost[MAX];
int activeID[MAX], activeCost[MAX];
int changed[MAGIC];
long long cost[MAX];
char type[MAX];
vector<int> edges[MAX];
unordered_map<int, int> cache[MAX];

void dfs (int node, int parent) {
    for (int i : edges[node]) {
        if (i != parent) {
            depth[i] = depth[node] + 1;
            ::parent[i][0]  = node;
            dfs (i, node);
        }
    }
}
void rebuild (int node, int parent) {
    for (int i : edges[node]) {
        if (i != parent) {
            cost[i] = selfCost[i] + cost[node];
            rebuild (i, node);
        }
    }
}
int LCA (int a, int b) {
    if (cache[a].count(b)) {
        return cache[a][b];
    }
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    for (int i = MAX_DEPTH - 1; i >= 0; i --) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = parent[a][i];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = MAX_DEPTH - 1; i >= 0; i --) {
        if (parent[a][i] != 0 && parent[b][i] != 0 && parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return cache[a][b] = cache[b][a] = parent[a][0];
}
template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int main(int argc, const char * argv[]) {
    //scanf("%d", &N);
    fastInput(N);
    for (int i = 1; i < N; i ++) {
        int x, y;
        //scanf("%d%d", &x, &y);
        fastInput(x);
        fastInput(y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    //scanf("%d", &Q);
    fastInput(Q);
    for (int i = 0; i < Q; i ++) {
        //scanf(" %c%d%d", &type[i], &x[i], &y[i]);
        scanf(" %c", &type[i]);
        fastInput(x[i]);
        fastInput(y[i]);
    }
    dfs(1, -1);
    for (int i = 1; i < MAX_DEPTH; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (parent[j][i - 1]) {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
        }
    }
    int lastBuild = 0;
    for (int i = 0; i < Q; i ++) {
        if (i > 0 && i % MAGIC == 0) {
            for (int j = lastBuild; j < i; j ++) {
                if (type[j] == 'T') {
                    selfCost[x[j]] = y[j];
                }
            }
            cost[1] = selfCost[1];
            rebuild(1, -1);
            lastBuild = i;
        }
        if (type[i] == 'Q') {
            if (x[i] == y[i]) {
                puts("0");
                continue;
            }
            int l = LCA(x[i], y[i]);
            long long result = cost[x[i]] + cost[y[i]] - 2 * cost[l] + selfCost[l];
            int selfCostX = selfCost[x[i]];
            int selfCostY = selfCost[y[i]];
            int activeCount = 0;
            for (int j = lastBuild; j < i; j ++) {
                if (type[j] == 'T') {
                    if (x[j] == x[i]) {
                        selfCostX = y[j];
                    }
                    else if(x[j] == y[i]) {
                        selfCostY = y[j];
                    }
                    if (LCA(x[j], l) == l && (LCA(x[i], x[j]) == x[j] || LCA(y[i], x[j]) == x[j])) {
                        changed[activeCount ++] = x[j];
                        activeID[x[j]] = 1;
                        activeCost[x[j]] = y[j];
                    }
                }
            }
            for (int j = activeCount - 1; j >= 0; j --) {
                int c = changed[j];
                if (activeID[c]) {
                    result = result - selfCost[c] + activeCost[c];
                    activeID[c] = 0;
                }
            }
            result -= selfCostX + selfCostY;
            printf("%lld\n", result);
        }
    }
    
    return 0;
}
