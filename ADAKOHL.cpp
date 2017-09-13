//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 Think what happens when you append a new digit.
 Suffix sums change and it can be easily handled in DP.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

const int MAX = 2000005;
const int modulo = 1000000007;

int N;
char ch;
int s[MAX];
int f[MAX], suffix[MAX];

int main(int argc, const char * argv[]) {
    /*
     f[n] = f[n - 1] + n * data[i] + suffix_sum[n - 1] * 10
     suffix_sum[n] = suffix_sum[n - 1] * 10 + n * data[i]
     */
    while((ch = getchar_unlocked()) != '\n') {
        s[++N] = ch - '0';
    }
    for (int i = 1; i <= N; i ++) {
        f[i] = (f[i - 1] + i * s[i] + 10LL * suffix[i - 1] % modulo) % modulo;
        suffix[i] = (10LL * suffix[i - 1] % modulo + i * s[i]) % modulo;
    }
    cout << f[N] << endl;
    
    return 0;
}
