//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/02/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N + Q * log(N) * MAX(K) / 32) solution using bitsets
 MAX(K) defines maximum of colors which can be up to 1000
 32 factor comes from bitsets (basically, 32 times faster than normal boolean array)
 For more precise definition of bitsets, please google it.
 Every query is just combination of 3 paths which can be handled seperately and results are better
  to be merged using bitsets.
 Binary lifting method is used for answering LCA(lowest common ancestor) queries rapidly.
 Although bitsets are powerful due to their 32 (even 64 -> depends on implementation) times faster
 performance, usually intended solutions are different from those using bitsets.
 */


#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

const int MAX = 300005;
const int MAGIC = 1001;
const int LOG = 19;

int N, K, Q;
int color[MAX];
int depth[MAX], parent[LOG][MAX];
bitset<MAGIC> bs[LOG][MAX];
vector<int> edges[MAX];

void dfs(int node, int parent) {
    for (int i : edges[node]) {
        if (i != parent) {
            depth[i] = depth[node] + 1;
            dfs(i, node);
        }
    }
}
int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    for (int i = LOG - 1; i >= 0; i --) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = parent[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = LOG - 1; i >= 0; i --) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

int main() {
    scanf("%d%d%d", &N, &K, &Q);
    for (int i = 2; i <= N; i ++) {
        scanf("%d", &parent[0][i]);
        ++parent[0][i];
        edges[parent[0][i]].push_back(i);
    }
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &color[i]);
        bs[0][i][color[i]] = 1;
        if (parent[0][i] != 0) {
            bs[0][i][color[parent[0][i]]] = 1;
        }
    }
    for (int i = 1; i < LOG; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (parent[i - 1][j] != 0) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
                bs[i][j] = bs[i - 1][j] | bs[i - 1][parent[i - 1][j]];
            }
        }
    }
    dfs(1, -1);
    while (Q --) {
        int u, v;
        bitset<MAGIC> result;
        for (int i = 0; i < 3; i ++) {
            scanf("%d%d", &u, &v);
            ++u;
            ++v;
            int l = LCA(u, v);
            for (int i = LOG - 1; i >= 0; i --) {
                if (depth[u] - (1 << i) >= depth[l]) {
                    result |= bs[i][u];
                    u = parent[i][u];
                }
            }
            for (int i = LOG - 1; i >= 0; i --) {
                if (depth[v] - (1 << i) >= depth[l]) {
                    result |= bs[i][v];
                    v = parent[i][v];
                }
            }
        }
        printf("%d\n", (int)result.count());
    }
    
    return 0;
}
