//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/7/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 An O(T * N * K) solution using dynamic programming
 The question is a form of popular knapsack problem
 And we just need to keep track of the last selected element
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1005;

int T, N, K;
int values[MAX], can[2][MAX];

int main() {
    scanf("%d", &T);
    for (int c = 0; c < T; c ++) {
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &values[i]);
        }
        for (int i = 0; i < 2; i ++) {
            for (int j = 1; j <= K; j ++) {
                can[i][j] = 0;
            }
        }
        can[0][0] = 1;
        for (int i = 1; i <= N; i ++) {
            for (int j = K; j > 0; j --) {
                can[0][j] |= can[1][j];
                if (j >= values[i]) {
                    can[1][j] |= can[0][j - values[i]];
                }
            }
        }
        int best = 0;
        for (int i = K; i > 0; i --) {
            if (can[0][i] || can[1][i]) {
                best = i;
                break;
            }
        }
        cout << "Scenario #" << c + 1 << ": " << best << endl;
    }
    
    return 0;
}

