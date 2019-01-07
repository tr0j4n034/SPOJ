//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/07/19.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(M * N / 32) solution using bitsets
 If you are not familiar with bitsets, I strongly recommend you
    to check it.
 Overall, memory complexity is also O(M * N / 32).
 The idea is that if we fix one of the endpoints of our path,
  the other element belongs
   to the set of elements spanned by adjacancy lists of
    neighboring elements.
 Although the naive way of implementing it is O(N^2), bitset speeds up
  the process by 32 factor.
 Note: It's possible to make this factor 64 (manual implementation)
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>
#include <utility>

using namespace std;

const int MAX_SIZE = 100001;

int N, M;
vector<pair<int, int>> edgeList;
vector<vector<int>> graph;
bitset<MAX_SIZE> adj[MAX_SIZE];

int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u != v) edgeList.push_back(make_pair(u, v));
    }
    sort(edgeList.begin(), edgeList.end());
    edgeList.erase(unique(edgeList.begin(), edgeList.end()), edgeList.end());
    graph.resize(N + 1);
    for (auto edge: edgeList) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    long long all = 0;
    for (int i = 1; i <= N; i ++) {
        bitset<MAX_SIZE> span;
        for (int neighbor: graph[i]) span |= adj[neighbor];
        all += max(int(span.count()) - 1, 0);
    }
    cout << all / 2 << endl;
    
    return 0;
}

