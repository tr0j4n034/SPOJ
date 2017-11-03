//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/03/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int T, N, K;

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &K);
        int result = 0;
        int x;
        for (int i = 0; i < N; i ++) {
            scanf("%d", &x);
            result = gcd(result, x);
        }
        assert(result != 1);
        int d = 0;
        for (int i = 1; i * i <= result; i ++) {
            if (result % i == 0) {
                if (i > 1) {
                    d = max(d, K / i * i);
                }
                d = max(d, K / (result / i) * (result / i));
            }
        }
        printf("%d\n", d);
    }
    
    return 0;
}
