//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/30/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100005;

int N, M;
int componentCount[2];
int componentID[2][MAX];
int degree[MAX];
bool visited[2][MAX];
vector<int> orders;
vector<int> Graph[MAX], reverseGraph[MAX];

void dfs1 (int node) {
    visited[0][node] = true;
    componentID[0][node] = componentCount[0];
    for (int i : reverseGraph[node]) {
        if (!visited[0][i]) {
            dfs1(i);
        }
    }
    orders.push_back(node);
}
void dfs2 (int node) {
    visited[1][node] = true;
    componentID[1][node] = componentCount[1];
    for (int i : Graph[node]) {
        if (!visited[1][i]) {
            dfs2(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        Graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }
    for (int i = 1; i <= N; i ++) {
        if (!visited[0][i]) {
            componentCount[0] ++;
            dfs1(i);
        }
    }
    reverse(orders.begin(), orders.end());
    for (int i : orders) {
        if (!visited[1][i]) {
            componentCount[1] ++;
            dfs2(i);
        }
    }
    //for (int i = 1; i <= N; i ++) {
    //    cout << i << " --> " << componentID[1][i] << endl;
    //}
    //cout << endl;
    for (int i = 1; i <= N; i ++) {
        for (int j : reverseGraph[i]) {
            if (componentID[1][i] != componentID[1][j]) {
                degree[componentID[1][j]] ++;
            }
        }
    }
    //for (int i = 1; i <= componentCount[1]; i ++) {
    //    cout << i << " --> " << degree[i] << endl;
    //}
    int startings = 0;
    for (int i = 1; i <= componentCount[1]; i ++) {
        if (!degree[i]) {
            startings ++;
        }
    }
    if (startings > 1) {
        puts("0");
    }
    else {
        vector<int> output;
        for (int i = 1; i <= N; i ++) {
            if (!degree[componentID[1][i]]) {
                output.push_back(i);
            }
        }
        printf("%d\n", (int)output.size());
        for (int i = 0; i < (int)output.size(); i ++) {
            printf("%d", output[i]);
            if (i < (int)output.size() - 1) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    
    return 0;
}
