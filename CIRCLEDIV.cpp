//
//  main.cpp
//  practice
//
//  Created by Mahmud on 09/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 In order to solve the problem:
  - you can just google with appropriate keywords
  - find the answer for smaller values of N, then use oeis
  - do some math
 In any case, probably, you will come up with O(T) solution...
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MODULO = 1000000007;

void add(int &a, int b) {
    a += b;
    if (a >= MODULO) {
        a -= MODULO;
    }
}
int gcd(int a, int b) { // naive version since b <= 4
    for (int i = b; i > 0; i --) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 0xabacaba;
}
int calculateCombination(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k > n) {
        return 0;
    }
    int d[5];
    for (int i = 1; i <= k; i ++) {
        d[i] = n - i + 1;
    }
    for (int i = 2; i <= k; i ++) {
        int divider = i;
        for (int j = 1; j <= k; j ++) {
            int g = gcd(d[j], divider);
            d[j] /= g;
            divider /= g;
        }
    }
    int result = 1;
    for (int i = 1; i <= k; i ++) {
        result = 1LL * result * d[i] % MODULO;
    }
    return result;
}
int calculate(int n) {
    int sum = 0;
    for (int i = 0; i <= 4; i ++) {
        add(sum, calculateCombination(n - 1, i));
    }
    return sum;
}

int main() {
    int T, N;
    scanf("%d", &T);
    for (int c = 0; c < T; c ++) {
        scanf("%d", &N);
        printf("Case %d: %d\n", c + 1, calculate(N));
    }

    return 0;
}
