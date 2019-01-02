//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/02/19.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O((N + Q) * log(N)) solution using MST + LCA
 The important observation is that the answer for a particular query (u, v)
    is equal to the weight of the largest edge
    between u and v in the MST of the graph.
 Therefore, firstly, we need to calculate MST of the given graph then using
    LCA the heaviest edge can be found in O(log(N)) via binary lifting.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

using namespace std;

const int MAX_SIZE = 1 << 17;
const int MAX_LEVELS = 17;

struct edge {
    int from;
    int to;
    int weight;
    edge() {}
    edge(int __from, int __to, int __weight) {
        from = __from;
        to = __to;
        weight = __weight;
    }
    bool operator < (const edge other) const{
        return weight < other.weight;
    }
};

struct dsu {
    int nodeCount;
    vector<int> parentsList;
    vector<int> rankList;
    vector<int> setSizes;
    
    dsu() {
        
    }
    dsu(int n) {
        nodeCount = n;
        parentsList.resize(n);
        iota(parentsList.begin(), parentsList.end(), 0);
        rankList.resize(n, 0);
        setSizes.resize(n, 1);
    }
    int findRepresentative(int node) {
        return node == parentsList[node] ?
        node : parentsList[node] = findRepresentative(parentsList[node]);
    }
    bool Union(int u, int v) {
        int root1 = findRepresentative(u);
        int root2 = findRepresentative(v);
        if (root1 == root2) {
            return false;
        }
        if (setSizes[root1] > setSizes[root2]) {
            swap(root1, root2);
        }
        setSizes[root2] += setSizes[root1];
        parentsList[root1] = root2;
        return true;
    }
};

vector<edge> mst(int N, vector<edge> edgeList) {
    dsu D = dsu(N);
    vector<edge> mstEdges;
    sort(edgeList.begin(), edgeList.end());
    for (auto e: edgeList) {
        if (D.Union(e.from, e.to)) {
            mstEdges.push_back(e);
        }
    }
    return mstEdges;
}

int N, M, Q;
vector<edge> edgeList;
vector<vector<edge>> graph;

int depthList[MAX_SIZE];
int parents[MAX_SIZE][MAX_LEVELS];
int jumpCosts[MAX_SIZE][MAX_LEVELS];

void dfs(int node, int parent) {
    for (auto e: graph[node]) {
        if (e.to != parent) {
            parents[e.to][0] = node;
            depthList[e.to] = depthList[node] + 1;
            jumpCosts[e.to][0] = e.weight;
            dfs(e.to, node);
        }
    }
}
int lca(int x, int y) {
    if (depthList[x] < depthList[y]) {
        swap(x, y);
    }
    for (int i = MAX_LEVELS - 1; i >= 0; i --) {
        if (depthList[x] >= depthList[y] + (1 << i)) {
            x = parents[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = MAX_LEVELS - 1; i >= 0; i --) {
        if (parents[x][i] != -1 && parents[y][i] != -1 && parents[x][i] != parents[y][i]) {
            x = parents[x][i];
            y = parents[y][i];
        }
    }
    return parents[x][0];
}
int getCost(int x, int jumpLevels) {
    int result = 0;
    for (int i = MAX_LEVELS - 1; i >= 0; i --) {
        if (jumpLevels >= (1 << i)) {
            result = max(result, jumpCosts[x][i]);
            x = parents[x][i];
            jumpLevels -= (1 << i);
        }
    }
    return result;
}


int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i ++) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        edgeList.push_back(edge(u, v, l));
    }
    vector<edge> mstEdges = mst(N, edgeList);
    graph.resize(N);
    for (auto e: mstEdges) { // not the best way though
        graph[e.from].push_back(e);
        graph[e.to].push_back(edge(e.to, e.from, e.weight));
    }
    for (int i = 0; i < MAX_LEVELS; i ++) {
        for (int j = 0; j < N; j ++) {
            parents[j][i] = -1;
        }
    }
    int root = 0;
    dfs(root, -1);
    for (int i = 1; i < MAX_LEVELS; i ++) {
        for (int j = 0; j < N; j ++) {
            if (parents[j][i - 1] != -1) {
                parents[j][i] = parents[parents[j][i - 1]][i - 1];
                jumpCosts[j][i] = max(jumpCosts[j][i - 1], jumpCosts[parents[j][i - 1]][i - 1]);
            }
        }
    }
    scanf("%d", &Q);
    while (Q --) {
        int u, v;
        scanf("%d%d", &u, &v);
        int l = lca(u, v);
        printf("%d\n", max(getCost(u, depthList[u] - depthList[l]),
                           getCost(v, depthList[v] - depthList[l])));
    }
    
    
    return 0;
}

