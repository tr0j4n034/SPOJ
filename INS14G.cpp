//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 13/07/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 1000025;
const int mod = 1000000007;

int T, N;
int fac[me], inv[me];

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
int power(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b & 1){
        return 1LL * power(a, b - 1) * a % mod;
    }
    int half = power(a, b >> 1);
    return 1LL * half * half % mod;
}
int inverse(int a){
    if(inv[a] != 0){
        return inv[a];
    }
    return inv[a] = power(fac[a], mod - 2);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fac[0] = 1;
    for(int i = 1; i < me; i ++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    fastInput(T);
    while(T --){
        fastInput(N);
        --N;
        printf("%d\n", 1LL * fac[N] * inverse(N >> 1) % mod * inverse((N + 1) >> 1) % mod);
    }
    
    return 0;
}
