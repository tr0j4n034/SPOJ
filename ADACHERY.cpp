//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/30/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <bitset>

using namespace std;

const int MAX = 100005;

int N, M;
int degree[MAX];
vector<pair<int, int>> edges;
bitset<MAX> bs[MAX];

int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        bs[u][v] = 1;
        bs[v][u] = 1;
        degree[u] ++;
        degree[v] ++;
        edges.push_back(make_pair(u, v));
    }
    long long all = 0, bad = 0;
    for(int i = 0; i < N; i ++) {
        all += 1LL * degree[i] * (degree[i] - 1) / 2;
    }
    for(auto i : edges) {
        bad += (bs[i.first] & bs[i.second]).count();
    }
    printf("%lld\n", all - bad);
    
    return 0;
}
