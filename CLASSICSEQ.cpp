//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(T * log(N)) solution using the matrix powers
  method for calculation of fibonacci numbers.
 Baiscally,
  fib(1)^2 + fib(2)^2 + ... + fib(n)^2 = fib(n) * fib(n + 1)
 Now, use a fast way to calculate those fibonacci values...
 */

#include <iostream>
#include <cmath>

using namespace std;

const int MODULO = 1000000007;

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
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % MODULO) % MODULO;
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

int main(int argc, const char * argv[]) {
    matrix F; // fibonacci base
    F.a[0][0] = 1; F.a[0][1] = 1;
    F.a[1][0] = 1; F.a[1][1] = 0;
    
    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> N;
        matrix Fn = power(F, N);
        cout << "Case " << c + 1 << ": " << 1LL * Fn.a[0][0] * Fn.a[0][1] % MODULO << endl;
    }
    
    return 0;
}

