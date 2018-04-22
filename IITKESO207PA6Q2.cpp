//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 100005;

int N, M;
vector<vector<int>> graph;

int timer = 0;
int visited[MAX];
int timeIN[MAX], fup[MAX];

int critical[MAX];
vector<int> articulation;

void dfs(int node, int parent = -1) {
    visited[node] = 1;
    timeIN[node] = fup[node] = timer ++;
    int children = 0;
    for (int i : graph[node]) {
        if (i == parent) continue;
        if (visited[i]) {
            fup[node] = min(fup[node], timeIN[i]);
        }
        else {
            dfs(i, node);
            fup[node] = min(fup[node], fup[i]);
            children ++;
            if (parent != -1 && fup[i] >= timeIN[node]) {
                critical[node] = 1;
            }
        }
    }
    if (parent == -1 && children > 1) critical[node] = 1;
}

int main() {
    while (scanf("%d%d", &N, &M)) {
        if (N == 0 && M == 0) break;
        graph.resize(N + 1);
        for (int i = 1; i <= N; i ++) graph[i].clear();
        for (int i = 1; i <= N; i ++) visited[i] = 0;
        for (int i = 1; i <= N; i ++) critical[i] = 0;
        for (int i = 0; i < M; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u ++;
            v ++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 1; i <= N; i ++) {
            if (!visited[i]) dfs(i);
        }
        //    for (int i = 1; i <= N; i ++) {
        //        if (critical[i]) articulation.push_back(i);
        //    }
        //        int result = 0;
        //        for (int i = 1; i <= N; i ++) {
        //            if (critical[i]) result ++;
        //        }
        //        printf("%d\n", result);
        for (int i = 1; i <= N; i ++) {
            if (critical[i]) printf("%d\n", i - 1);
        }
        return 0;
    }
    
    return 0;
}
