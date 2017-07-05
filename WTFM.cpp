//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 6/07/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 1000025;
const int LOG = 20;

int N, Q, K;
int value[me], composite[me], divisors[me], has[me], parent[LOG][me], depth[me];
vector<int> edges[me];

void dfs(int node, int p){
    parent[0][node] = p;
    has[node] += (int)(divisors[value[node]] >= K);
    for(int i : edges[node]){
        if(i == p){
            continue;
        }
        depth[i] = depth[node] + 1;
        has[i] += has[node];
        dfs(i, node);
    }
}
int lca(int a, int b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }
    for(int i = LOG - 1; i >= 0; i --){
        if(depth[a] - (1 << i) >= depth[b]){
            a = parent[i][a];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = LOG - 1; i >= 0; i --){
        if(parent[i][a] != 0 && parent[i][b] != 0 && parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < me; i ++){
        if(composite[i]){
            continue;
        }
        for(int j = i; j < me; j += i){
            divisors[j] ++;
            composite[j] = 1;
        }
    }
    scanf("%d%d%d", &N, &K, &Q);
    for(int i = 1; i <= N; i ++){
        scanf("%d", &value[i]);
    }
    for(int i = 1; i < N; i ++){
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, -1);
    for(int i = 1; i < LOG; i ++){
        for(int j = 1; j <= N; j ++){
            if(parent[i - 1][j] != 0){
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }
    while(Q --){
        int u, v;
        scanf("%d%d", &u, &v);
        int l = lca(u, v);
        printf("%d\n", has[u] + has[v] - 2 * has[l] + (int)(divisors[value[l]] >= K));
    }
    
    return 0;
}
