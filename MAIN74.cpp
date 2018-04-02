//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cassert>

using namespace std;

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

int T;
long long N;
matrix F;

int main() {
    
    cin >> T;
    while (T --) {
        cin >> N;
        if (N == 0) {
            cout << 0 << endl;
            continue;
        }
        if (N == 1) {
            cout << 2 << endl;
            continue;
        }
        F.a[0][0] = 1;
        F.a[0][1] = 1;
        F.a[1][0] = 1;
        F.a[1][1] = 0;
        F = power(F, N + 2);
        
        cout << F.a[0][0] << endl;
    }
    
    return 0;
}
