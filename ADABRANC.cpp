//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/19/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 O((N + Q) * log(N + Q)) solution by Disjoint Set Union (DSU)
 Let's consider the process of adding the edges as queries.
 So we get two types of queries:
 1) add an edge
 2) calculate how many nodes can be reached from current node
 If we sort these queries by "x" (weight), all queries can be easily handled by DSU.
 */


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 300005;

struct event{
    int type; // 0 - add, 1 - query
    int id;
    int a;
    int b;
    int weight;
    event() {
        
    }
    event(int _type, int _id, int _a, int _b, int _weight):
    type(_type), id(_id), a(_a), b(_b), weight(_weight) {
        
    }
    bool operator < (const event other) const {
        if (weight != other.weight) {
            return weight > other.weight;
        }
        return type < other.type;
    }
};


int N, M, Q;
int parent[MAX], componentSize[MAX];
int result[MAX];
vector<event> events;

int findRoot(int node) {
    return parent[node] == node ? node : parent[node] = findRoot(parent[node]);
}
void unionNodes(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);
    if (rootX == rootY) {
        return;
    }
    if (rand() & 1) {
        swap(rootX, rootY);
    }
    parent[rootY] = rootX;
    componentSize[rootX] += componentSize[rootY];
    componentSize[rootY] = 0;
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 1; i <= N; i ++) {
        parent[i] = i;
        componentSize[i] = 1;
    }
    for (int i = 0; i < M; i ++) {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        ++a;
        ++b;
        events.push_back(event(0, -1, a, b, l));
    }
    for (int i = 0; i < Q; i ++) {
        int a, x;
        scanf("%d%d", &a, &x);
        ++a;
        events.push_back(event(1, i, a, -1, x));
    }
    sort(events.begin(), events.end());
    for (auto i : events) {
        if (i.type == 0) {
            unionNodes(i.a, i.b);
        }
        else {
            result[i.id] = componentSize[findRoot(i.a)];
        }
    }
    for (int i = 0; i < Q; i ++) {
        printf("%d\n", result[i]);
    }
    
    return 0;
}

