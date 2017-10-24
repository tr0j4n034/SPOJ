//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/24/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 Obvious solution is matrix exponentation which is O(N^3 * log(T)).
 Of course, matrix expnonentation will not work here, because N is up to 50000.
 I searched for small values of N.
 http://oeis.org/search?q=2%2C+6%2C+10%2C+22%2C+42&sort=&language=english&go=Search
 http://oeis.org/search?q=3%2C+6%2C+21%2C+60&language=english&go=Search
 http://oeis.org/search?q=4%2C+12%2C+52&language=english&go=Search
 As always, oeis does the job:
 ---> The elements of the transformation matrix will be
 equal to the number of closed walks of length m along the edges of a m-gon based at a vertex.
 
 oeis <3 <3 <3
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 50005;
const int MODULO = 98765431;

int N, T;
int data[MAX];

int power(int a, int b, int modulo) {
    if (b == 0) {
        return 1 % modulo;
    }
    if (b & 1) {
        return 1LL * power(a, b - 1, modulo) * a % modulo;
    }
    int half = power(a, b >> 1, modulo);
    return 1LL * half * half % modulo;
}
int inverse(int a, int modulo) {
    return power(a, modulo - 2, modulo);
}

int main() {
    // f(n, m) = (n^m + (-1)^m * n) / (n + 1)
    // if m is odd: next = f(n, m) + 1
    // else: next = f(n, m) - 1
    
    scanf("%d%d", &N, &T);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &data[i]);
    }
    --N;
    
    int f, s;
    f = 1LL * (power(N, T, MODULO) + N * (T % 2 == 1 ? -1 : 1)) * inverse(N + 1, MODULO) % MODULO;
    s = (T % 2 == 1) ? (f + 1 + MODULO) % MODULO : (f - 1) % MODULO;
    ++N;
    
    long long allSum = 0;
    for (int i = 1; i <= N; i ++) {
        allSum = (allSum + data[i]) % MODULO;
    }
    for (int i = 1; i <= N; i ++) {
        long long result = (1LL * data[i] * f % MODULO + 1LL * (allSum - data[i] + MODULO) % MODULO * s) % MODULO;
        printf("%lld\n", result % MODULO);
    }
    return 0;
}
