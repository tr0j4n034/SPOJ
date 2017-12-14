//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/14/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * log(log(N)) + T) solution using dynamic programming.
 Prime divisors and sigma function for each number can be calculated sieve like approach.
 The dp - main part of the program can be solve in the following manner:
    Let dp table indicate if we win if there are N stones initially...
     (dp[N] = 1 --> we win, dp[N] = 0 --> we lose)
     ---> base case: dp[0] = 0
     ---> dp[N] = 1 if there is at least one M in [N - sigma[N], N - 1] for which dp[M] = 0
     The easiest way to check this condition is
      to keep a prefix sum table for previous values of dp array,
       then check if there exists dp[M] = 0 or not.
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 20000005;

int T, N;
int lp[MAX], sigma[MAX], dp[MAX], dpSum[MAX];

int main() {
    for (int i = 2; i * i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) lp[j] = i;
    }
    cerr << "assigning divisors done in: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    for (int i = 2; i < MAX; i ++) {
        if (!lp[i]) lp[i] = i;
    }
    
    sigma[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        int counter = 0, j = i;
        while (j % lp[i] == 0) {
            counter ++;
            j /= lp[i];
        }
        sigma[i] = sigma[j] * (counter + 1);
    }
    cerr << "calculating sigmas done in: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    dp[0] = 0;
    for (int i = 1; i < MAX; i ++) {
        int low = i - sigma[i];
        if (low == 0 || dpSum[i - 1] - dpSum[low - 1] != sigma[i]) dp[i] = 1;
        else dp[i] = 0;
        dpSum[i] = dpSum[i - 1] + dp[i];
    }
    cerr << "calculating dp table done in: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        puts(dp[N] == 0 ? "Vinit" : "Ada");
    }
    
    return 0;
}
