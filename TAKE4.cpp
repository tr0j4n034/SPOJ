//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/15/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 An interesting dynamic programming problem
 My solution runs in O(MAX * MAX + T) time
 From the first sight, the problem has O(T * N * M) or O(MAX * MAX * MAX) solution
 which obviously get time limit exceeded verdict.
 In order to fasten the process, I just used a prefix sum table which helps to find out
 whether there is 0 in the corresponding range.
 Please, be careful when analyzing code in lines 37-47.
 */

#include <iostream>

using namespace std;

const int MAX = 2005;

int T, N, M;
int dp[MAX][MAX], columnSum[MAX][MAX];

int f(int N, int M) {
    if (dp[N][M] != -1) {
        return dp[N][M];
    }
    if (N <= M) {
        columnSum[M][N] = columnSum[M][N - 1] + 1;
        return dp[N][M] = 1;
    }
    for (int i = 1; i <= M; i ++) {
        //if (!f(N - i, M)) {
        //    dp[N][M] = 1;
        //    break;
        //}
        int rangeSum = columnSum[M][N - 1] - columnSum[M][N - M - 1];
        if (rangeSum != M) {
            dp[N][M] = 1;
            break;
        }
    }
    if (dp[N][M] == -1) {
        dp[N][M] = 0;
    }
    columnSum[M][N] = columnSum[M][N - 1] + dp[N][M];
    return dp[N][M];
}

int main() {
    for (int i = 1; i < MAX; i ++) {
        for (int j = 1; j < MAX; j ++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i < MAX; i ++) {
        for (int j = 1; j < MAX; j ++) {
            //cout << i << " vs " << j << "  --> " << f(i, j) << endl;
            f(i, j);
        }
    }
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    cin >> T;
    while (T --) {
        cin >> N >> M;
        if (dp[N][M] == 1) {
            cout << "player1 wins" << endl;
        }
        else {
            cout << "player2 wins" << endl;
        }
    }
    
    return 0;
}

