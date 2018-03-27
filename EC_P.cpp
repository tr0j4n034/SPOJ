//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/26/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int MAX = 705;

int T, N, M;
int timer;
int visited[MAX], timeIN[MAX], fup[MAX];
vector<vector<int>> graph;
vector<pair<int, int>> bridges;

void dfs(int node, int parent = -1) {
    visited[node] = 1;
    fup[node] = timeIN[node] = ++timer;
    for (int i : graph[node]) {
        if (i == parent) continue;
        if (visited[i]) {
            fup[node] = min(fup[node], timeIN[i]);
        }
        else {
            dfs(i, node);
            fup[node] = min(fup[node], fup[i]);
            if (fup[i] > timeIN[node]) {
                bridges.push_back(make_pair(min(node, i), max(node, i)));
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    for (int c = 0; c < T; c ++) {
        scanf("%d%d", &N, &M);
        graph.resize(N + 1);
        for (int i = 1; i <= N; i ++) graph[i].clear();
        for (int i = 0; i < M; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        timer = 0;
        bridges.clear();
        for (int i = 1; i <= N; i ++) visited[i] = 0;
        for (int i = 1; i <= N; i ++) {
            if (!visited[i]) dfs(i);
        }
        sort(bridges.begin(), bridges.end());
        bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());
        
        printf("Caso #%d\n", c + 1);
        if (bridges.empty()) puts("Sin bloqueos");
        else {
            printf("%d\n", (int)bridges.size());
            for (auto i : bridges) printf("%d %d\n", i.first, i.second);
        }
    }
    
    return 0;
}
