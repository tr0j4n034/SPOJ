//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * K * K) solution using 'DP on trees' technique.
 We need to consider how child nodes contribute to the result of particular parent node.
 Let dp[i] be the the number of all satisfying subtrees;
 And subtreeCount[i][j] is the number of subtrees of node i having size j (containing node i itself).
 Then subtreeCount[i][j] can be derived from corresponding values of each child node of i.
 As it is obvious, the answer is equal to dp[root].
 */

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2505;
const int SIZE = 95;
const int MODULO = 10243;

void add(int &a, int b) {
    a += b;
    if (a >= MODULO) {
        a -= MODULO;
    }
}
void multiply(int *a, int *b) {
    int c[SIZE];
    for (int i = 0; i < SIZE; i ++) {
        c[i] = a[i];
    }
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 1; j < i; j ++) {
            add(a[i], b[j] * c[i - j] % MODULO);
        }
    }
}

int N, K;
int dp[MAX], subtreeCount[MAX][SIZE];
vector<int> edges[MAX];

void dfs(int node, int parent) {
    subtreeCount[node][1] = 1;
    for (int i : edges[node]) {
        if (i == parent) {
            continue;
        }
        dfs(i, node);
        multiply(subtreeCount[node], subtreeCount[i]);
    }
    dp[node] = subtreeCount[node][K];
    for (int i : edges[node]) {
        if (i == parent) {
            continue;
        }
        add(dp[node], dp[i]);
    }
}

int main() {
    cin >> N >> K;
    for (int i = 1; i < N; i ++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i <= N; i ++) {
        subtreeCount[i][0] = 1;
    }
    dfs(1, -1);

    cout << dp[1] << endl;
    
    return 0;
}
