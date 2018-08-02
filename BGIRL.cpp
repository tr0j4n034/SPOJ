//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int S = 1 << 17;

int T, N, M;
vector<int> was;

void dfs(int node, vector<vector<int>> &graph, int &size) {
    was[node] = 1;
    ++size;
    for (int neighbor: graph[node]) {
        if (!was[neighbor]) {
            dfs(neighbor, graph, size);
        }
    }
}

int main() {
    vector<int> primes(S, 1);
    primes[1] = 0;
    for (int i = 2; i < S; i ++) {
        if (!primes[i]) {
            continue;
        }
        for (int j = i + i; j < S; j += i) {
            primes[j] = 0;
        }
    }
    
    cin >> T;
    while (T --) {
        cin >> N >> M;
        vector<vector<int>> graph(N + 1);
        was.assign(N + 1, 0);
        for (int i = 0; i < M; i ++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int best = -1;
        for (int i = 1; i <= N; i ++) {
            if (was[i]) {
                continue;
            }
            int size = 0;
            dfs(i, graph, size);
            if (primes[size] && size > best) {
                best = size;
            }
        }
        cout << best << endl;
    }
    
    return 0;
}
