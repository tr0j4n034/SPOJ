//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/15/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

/*
 A simple dynamic programming solution.
 We have O(n^3) different states where each state is
  the optimal value for subarray [i, j] with final toxicity level k.
 This yields to the recurrence:
  f(i, j, k) = minimum of
            [f(i, lhs, khat) + f(lhs + 1, j, (k - khat) % 100) + khat * (k - khat) % 100]
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

const int SIZE = 100;

int T, N;
int values[SIZE], dp[SIZE][SIZE][SIZE];
vector<int> available[SIZE][SIZE];

int main(int argc, const char* argv[]) {
    auto minimize = [&](int &lhs, int rhs) {
        if (rhs < lhs) lhs = rhs;
    };
    
    // cin >> T;
    T = 1;
    while (T --) {
        cin >> N;
        assert(N != 1);
        for (int i = 0; i < N; i ++) cin >> values[i];
        for (int i = 0; i < N; i ++) {
            for (int j = i; j < N; j ++) {
                for (int k = 0; k < SIZE; k ++) {
                    dp[i][j][k] = INT_MAX;
                }
            }
        }
        for (int i = 0; i < N; i ++) {
            dp[i][i][values[i]] = 0;
            available[i][i].push_back(values[i]);
        }
        for (int i = 0; i < N - 1; i ++) {
            dp[i][i + 1][(values[i] + values[i + 1]) % SIZE] = values[i] * values[i + 1];
            available[i][i + 1].push_back((values[i] + values[i + 1]) % SIZE);
        }
        for (int l = 2; l <= N; l ++) {
            for (int i = 0; i + l - 1 < N; i ++) {
                int j = i + l - 1;
                for (int lhs = i; lhs < j; lhs ++) {
                    for (auto k: available[i][lhs]) {
                        for (auto q: available[lhs + 1][j]) {
                            if (dp[i][j][(k + q) % SIZE] == INT_MAX) {
                                available[i][j].push_back((k + q) % SIZE);
                            }
                            minimize(dp[i][j][(k + q) % SIZE], dp[i][lhs][k] + dp[lhs + 1][j][q] + k * q);
                        }
                    }
                }
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < SIZE; i ++) {
            minimize(result, dp[0][N - 1][i]);
        }
        cout << result << endl;
    }
    
    return 0;
}
