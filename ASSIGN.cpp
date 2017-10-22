//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/22/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * 2^N * N^2) solution using bitmask technique
 Think this way: For each mask, how much current row can contribute to answer?
 */


#include <iostream>

using namespace std;

const int MAX = 20;

int T, N;
int a[MAX][MAX];
long long dp[MAX][1 << MAX];

int main() {
    cin >> T;
    while (T --) {
        cin >> N;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < (1 << N); j ++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i ++) {
            if (a[0][i]) {
                dp[0][1 << i] = 1;
            }
        }
        for (int i = 1; i < N; i ++) {
            for (int k = 0; k < N; k ++) {
                if (!a[i][k]) {
                    continue;
                }
                for (int j = 0; j < (1 << N); j ++) {
                    if ((j >> k) & 1) {
                        dp[i][j] += dp[i - 1][j ^ (1 << k)];
                    }
                }
            }
        }
        long long result = 0;
        for (int i = 0; i < (1 << N); i ++) {
            result += dp[N - 1][i];
        }
        cout << result << endl;
    }
    
    return 0;
}
