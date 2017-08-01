//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/1/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>

using namespace std;

int power(int a, int b, int modulo) {
    if(b == 0) {
        return 1 % modulo;
    }
    if(b & 1) {
        return 1LL * power(a, b - 1, modulo) * a % modulo;
    }
    int half = power(a, b >> 1, modulo);
    return 1LL * half * half % modulo;
}
int getSum(int r, int k, int modulo) {
    if(k == 0) {
        return 0;
    }
    if(k & 1) {
        return getSum(r, k - 1, modulo) + power(r, k, modulo);
    }
    return 1LL * (power(r, k >> 1, modulo) + 1) * getSum(r, k >> 1, modulo) % modulo;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T --) {
        int a0, d, r, n, mod;
        cin >> a0 >> d >> r >> n >> mod;
        n --;
        int result = 1LL * (a0 + d) * power(r, n >> 1, mod) % mod;
        result = (result + 1LL * d * getSum(r, (n >> 1) - 1, mod)) % mod;
        if(n & 1) {
            result = (result + d) % mod;
        }
        cout << result << endl;
    }
    
    return 0;
}
