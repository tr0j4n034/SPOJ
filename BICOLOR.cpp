//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/04/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N + M) solution using simple dfs traversal.
 The problem just asks whether the graph is bipartite or not.
 Just do a dfs or bfs traversal of the graph and check if the conflict occurs or not.
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1105;

int N, M;
bool visited[MAX];
int color[MAX];
vector<int> edges[MAX];

bool dfs(int node, int c) {
    visited[node] = 1;
    color[node] = c;
    bool result = true;
    for (int i : edges[node]) {
        if (color[i] == c) {
            result = false;
            break;
        }
        if (!visited[i]) {
            result &= dfs(i, 1 - c);
        }
    }
    return result;
}

int main() {
    while (scanf("%d", &N)) {
        if (N == 0) {
            break;
        }
        scanf("%d", &M);
        for (int i = 0; i < N; i ++) {
            edges[i].clear();
            visited[i] = 0;
            color[i] = -1;
        }
        for (int i = 0; i < M; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        bool result = true;
        for (int i = 0; i < N && result; i ++) {
            if (!visited[i]) {
                result &= dfs(i, 0);
            }
        }
        if (result == true) {
            puts("BICOLORABLE");
        }
        else {
            puts("NOT BICOLORABLE");
        }
    }
    
    return 0;
}
