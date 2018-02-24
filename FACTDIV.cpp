//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/24/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

const int MODULO = 1000000007;
const int MAX = 1000005;

template <class T>
void fastInput(T &N) {
    char ch;
    N = 0;
    while ((ch = getchar_unlocked()) && ch == ' ') {};
    if (isdigit(ch)) N = ch - '0';
    while ((ch = getchar_unlocked()) && isdigit(ch)) {
        N = (N << 1) + (N << 3) + ch - '0';
    }
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

int power(int a, int b) {
    int result = 1, current = a;
    while (b) {
        if (b & 1) result = 1LL * result * current % MODULO;
        current = 1LL * current * current % MODULO;
        b >>= 1;
    }
    return result;
}


int inverse[MAX];
int p[MAX], f[MAX], counts[MAX];

void showTime() {
    cout.precision(10);
    cerr << fixed << "elapsed: " << 1. * clock() / CLOCKS_PER_SEC << endl;
}

int main() {
    for (int i = 1; i < MAX; i ++) {
        inverse[i] = power(i, MODULO - 2);
    }
    showTime();
    iota(p, p + MAX, 0);
    showTime();
    
    for (int i = 2; i * i < MAX; i ++) {
        if (p[i] != i) continue;
        for (int j = i * i; j < MAX; j += i) p[j] = i;
    }
    showTime();
    fill(counts, counts + MAX, 1);
    showTime();
    
    int current = 1;
    for (int i = 1; i < MAX; i ++) {
        int j = i;
        while (j > 1) {
            int divisor = p[j];
            int dcount = 0;
            while (j % divisor == 0) {
                j /= divisor;
                dcount ++;
            }
            current = 1LL * current * inverse[counts[divisor]] % MODULO;
            counts[divisor] += dcount;
            current = 1LL * current * counts[divisor] % MODULO;
        }
        f[i] = current;
    }
    showTime();
    for (int i = 1; i < MAX; i ++) {
        f[i] = (f[i - 1] + f[i]) % MODULO;
    }
    showTime();
    
    int T, L, R;
    
    fastInput(T);
    while (T --) {
        fastInput(L);
        fastInput(R);
        fastPrint((f[R] - f[L - 1] + MODULO) % MODULO);
    }
    
    return 0;
}

