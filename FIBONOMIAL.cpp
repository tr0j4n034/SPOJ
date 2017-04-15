//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 15/11/17.
//  Copyright ÃÂ© 2017 Mahmud. All rights reserved.
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
#include <unordered_set>
#include <map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>
 
using namespace std;
 
const int me = 1025;
const int mod = 1000000007;
 
struct matrix{
    long long a[2][2];
    matrix() {
        for(int i = 0; i < 2; i ++)
            for(int j = 0; j < 2; j ++)
                a[i][j] = 0;
    }
};
 
matrix mul(matrix a, matrix b){
    matrix c;
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 2; j ++)
            c.a[i][j] = 0;
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 2; j ++)
            for(int k = 0; k < 2; k ++)
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
    return c;
}
matrix power(matrix a, long long b){
    if(b == 1)
        return a;
    if(b & 1)
        return mul(power(a, b - 1), a);
    matrix half = power(a, b >> 1);
    return mul(half, half);
}
long long power(long long a, long long b){
    if(b == 0)
        return 1 % mod;
    if(b & 1)
        return 1LL * power(a, b - 1) * a % mod;
    long long half = power(a, b >> 1);
    return 1LL * half * half % mod;
}
long long inverse(long long a){
    return power(a % mod, mod - 2);
}
 
int T;
long long N, X;
 
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> T;
    //T = 1000;
    while(T --){
        cin >> N >> X;
        //N = rand() * rand() * rand() * rand() * rand() % (long long)(1.e15) + 1;
        //X = rand() * rand() * rand() * rand() * rand() % (long long)(1.e15) + 1;
        //N = llabs(N), X = llabs(X);
        //cout << N << " and " << X << endl;
        if(X == 0 || N == 0){
            cout << 0 << endl;
            continue;
        }
        assert(N > 0 && N <= (long long)1.e15);
        assert(X > 0 && X <= (long long)1.e15);
        matrix F;
        F.a[0][0] = 1;
        F.a[0][1] = 1;
        F.a[1][0] = 1;
        F.a[1][1] = 0;
        
        matrix Fn = power(F, N);
        matrix Fnp = mul(F, Fn);
        long long dividend = ((X % mod) * (X % mod) % mod + (X % mod) - 1 + mod) % mod;
        long long result = (X % mod) *
        ((power(X, N) * ((X % mod * Fn.a[0][1] % mod + Fnp.a[0][1]) % mod) % mod - 1 + mod) % mod) % mod *
        inverse(dividend) % mod;
        cout << result << endl;
    }
    
    return 0;
}