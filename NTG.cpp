//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/23/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * log(N) + T) solution based on prime factorization and sieves
 First, transform the function described in the statement:
  f(l, r) = f(1, r) - f(1, l - 1)
 And simply:
  f(1, r) = f(1, r - 1) + p(r)
 If we can calculate p(i) for every number in range (1, 10^5), we are done...
 Calculating p function can be done in the following way:
    p(i) = sum of gcd(i, j) where j is in (1, i) inclusive
    actually it is equal to:
     p(i) = sum of j * phi(i / j) where j is a divisor of i
 Use last identity to find all p(i)-s and fill cumulative sums table (dp).
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100005;
const int MAX_DIVISORS = 130;
const int MODULO = 1000000007;

int power(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return 1LL * power(a, b - 1) * a % MODULO;
    int half = power(a, b >> 1);
    return 1LL * half * half % MODULO;
}

int K, T, l, r;
int divisorCount[MAX], divisors[MAX][MAX_DIVISORS];
int lp[MAX], phi[MAX];
int powers[MAX], dp[MAX];

int main() {
    for (int i = 1; i < MAX; i ++) {
        for (int j = i; j < MAX; j += i) {
            divisors[j][divisorCount[j] ++] = i;
        }
    }
    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) {
            lp[j] = i;
        }
    }
    phi[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        int j = i / lp[i];
        if (j % lp[i] == 0) phi[i] = phi[j] * lp[i];
        else phi[i] = phi[j] * (lp[i] - 1);
    }
    
    scanf("%d%d", &K, &T);
    for (int i = 1; i < MAX; i ++) powers[i] = power(i, K);
    for (int i = 1; i < MAX; i ++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < divisorCount[i]; j ++) {
            dp[i] = (dp[i] + 1LL * powers[divisors[i][j]] * phi[i / divisors[i][j]] % MODULO) % MODULO;
        }
    }
    while (T --) {
        scanf("%d%d", &l, &r);
        printf("%d\n", (dp[r] - dp[l - 1] + MODULO) % MODULO);
    }
    
    return 0;
}
