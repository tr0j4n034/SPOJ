//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 7/07/17.
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

const int me = 2525;
const int mod = 1000000007;

int c[me][me], cnt[me];

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
    return power(a, mod - 2);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    int MAGIC = inverse(2);
    
    for(int i = 0; i < me; i ++){
        for(int j = 0; j <= i; j ++){
            if(j == 0){
                c[i][j] = 1;
            }
            else{
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }
    
    int T, N;
    cin >> T;
    while(T --){
        cin >> N;
        int result = 0;
        for(int i = 1; i <= N; i ++){
            for(int j = i + 1; j <= N; j ++){
                result = (result + 1LL * __gcd(i, j) * c[N][i] % mod * c[N][j] % mod) % mod;
            }
            result = (result + 1LL * i * c[N][i] % mod * (c[N][i] + mod - 1) % mod * MAGIC % mod) % mod;
        }
        cout << result << endl;
    }
    
    return 0;
}
