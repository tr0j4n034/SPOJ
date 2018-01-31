//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/30/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 O(N^4) solution by my teammate Rashad Mammadov
 Solution can be reduced to O(N^3) by optimising partial sum section.
 */

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

const int MAX = 64;

unsigned long long dp[MAX][MAX];
unsigned long long f[MAX], prefix[MAX];

int main() {
    for (int n = 1; n < MAX; n ++) {
        for (int k = 0; k <= n; k ++) {
            for (int i = 0; i <= n; i ++) f[i] = 0;
            for (int i = 0; i <= k; i ++) f[i] = 1LL << i;
            for (int i = k + 1; i <= n; i ++) {
                for (int j = max(i - k - 1, 0); j < i; j ++) f[i] += f[j];
                assert(f[i] > 0 && 1. * f[i] < 19.e18);
            }
            //cout << "n = " << n << ", k = " << k << " --> " << dp[n][k] << endl;
            dp[n][k] = f[n];
        }
    }
    for (int n = 1; n < MAX; n ++) {
        for (int k = n; k > 0; k --) {
            dp[n][k] -= dp[n][k - 1];
        }
    }
    for (int n = 1; n < MAX; n ++) {
        for (int k = 0; k <= n; k ++) {
            cout << dp[n][k];
            if (k < n) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
