//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/19/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T + N * log(N)) solution
 N corresponds to the maximum value of input numbers which can be up to 10^7.
 log(N) factor comes from the process of finding modular inverses.
 Actually, I just searched for the number '632' in OEIS (because 632 is not a common numbers :))
  The first sequence having 632 as its element, happily, matches with other input numbers as well.
  Now just implement what is necessary for the formula.
  A few precomputations and that is all...
 */

#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

const int MAX = 10000005;
const int MODULO = 1000000007;

int T, N;
int inv[MAX];
int phi[MAX], lp[MAX];
int powers[MAX];
int dp[MAX];

int power(int a, int b) {
    if (b == 0) return 1 % MODULO;
    if (b & 1) return 1LL * a * power(a, b - 1) % MODULO;
    int half = power(a, b >> 1);
    return 1LL * half * half % MODULO;
}
int inverse(int a) {
    if (inv[a] != 0) return inv[a]; // caching...
    return inv[a] = power(a, MODULO - 2);
}
void add(int &a, int b) {
    a += b;
    if (a >= MODULO) a -= MODULO;
}
template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

template<class T> void fastPrint(T n){
    if(n == 0){
        puts("0");
        return;
    }
    char buffer[256];
    int ptr = 0, sign = 1;
    
    if(n < 0){
        sign = -1;
        n *= -1;
    }
    while(n > 0){
        buffer[ptr ++] = (char)(n % 10 + '0');
        n /= 10;
    }
    if(sign == -1)
        putchar_unlocked('-');
    for(int i = ptr - 1; i >= 0; i --)
        putchar_unlocked(buffer[i]);
    putchar_unlocked('\n');
}

int main() {
    phi[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        if (!lp[i]) {
            for (int j = i; j < MAX; j += i) lp[j] = i;
        }
    }
    for (int i = 2; i < MAX; i ++) {
        int j = i / lp[i];
        if (j % lp[i] == 0) phi[i] = phi[j] * lp[i];
        else phi[i] = phi[j] * (lp[i] - 1);
    }
    cerr << "done in " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    powers[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        powers[i] = (powers[i - 1] << 1) % MODULO;
    }
    for (int i = 1; i < MAX; i ++) {
        for (int j = i; j < MAX; j += i) {
            add(dp[j], 1LL * phi[i] * powers[j / i] % MODULO);
        }
    }
    cerr << "done in " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    //scanf("%d", &T);
    fastInput(T);
    while (T --) {
        //scanf("%d", &N);
        fastInput(N);
        //printf("%d\n", (int)(1LL * dp[N] * inverse(N) % MODULO));
        fastPrint((int)(1LL * dp[N] * inverse(N) % MODULO));
    }
    
    return 0;
}
