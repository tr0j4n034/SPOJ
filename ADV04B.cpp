//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/1/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 sequence found in: http://oeis.org/search?q=1%2C+3%2C+13%2C+63&language=english&go=Search
 The rest is just generating thw whole sequence.
 */


#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1005;
const int modulo = 1000003;

int T, N;
int g[MAX];

int binaryPower (int a, int b, int modulo) {
    if (b == 0) {
        return 1 % modulo;
    }
    if (b & 1) {
        return 1LL * binaryPower(a, b - 1, modulo) * a % modulo;
    }
    int half = binaryPower(a, b >> 1, modulo);
    return 1LL * half * half % modulo;
}
int inverse (int a, int modulo) {
    return binaryPower(a, modulo - 2, modulo);
}

int main() {
    g[0] = 1;
    g[1] = 3;
    for (int i = 2; i < MAX; i ++) {
        g[i] = 1LL * (3LL * (2 * i - 1) * g[i - 1] % modulo - 1LL * (i - 1) * g[i - 2] % modulo + modulo) % modulo
        * inverse(i, modulo) % modulo;
    }
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        printf("%d\n", g[N - 1]);
    }
    
    return 0;
}

