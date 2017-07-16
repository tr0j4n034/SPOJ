//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 16/07/17.
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
//#include <unordered_map>
//#include <unordered_set>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 10000025;
const int mod = 1000000007;

int prime[me], tot[me], lp[me], f[me], fac[me];

int power(int a, int b){
    if(b == 0){
        return 1 % mod;
    }
    if(b & 1){
        return 1LL * power(a, b - 1) * a % mod;
    }
    int half = power(a, b >> 1);
    return 1LL * half * half % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++){
        if(!prime[i]){
            lp[i] = i;
            for(int j = i + i; j < me; j += i){
                prime[j] = 1;
                lp[j] = i;
            }
        }
    }
    for(int i = 2; i < me; i ++){
        prime[i] = prime[i - 1] + 1 - prime[i];
    }
    tot[1] = 1;
    for(int i = 2; i < me; i ++){
        int j = i / lp[i];
        if(j % lp[i] == 0){
            tot[i] = tot[j] * lp[i];
        }
        else{
            tot[i] = tot[j] * (lp[i] - 1);
        }
    }
    for(int i = 1; i < me; i ++){
        f[i] = prime[i] - tot[i];
        if(f[i] < 0){
            f[i] = 0;
        }
    }
    fac[0] = 1;
    for(int i = 1; i < me; i ++){
        fac[i] = 1LL * fac[i - 1] * i % (mod - 1);
    }
    
    int T, N;
    cin >> T;
    while(T --){
        cin >> N;
        cout << power(tot[N], fac[f[N]]) << endl;
    }
    
    return 0;
}
