//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/14/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

/*
 F(n) = C(n, 2) + C(n, 4) + 1
  where C(n, k) denotes the binomial coefficient.
 */

#include <iostream>

using namespace std;

const int MODULO = 1000000007;

int power(int base, int exponent, int modulo = MODULO) {
    if (exponent == 0) return 1 % modulo;
    if (exponent & 1) return 1LL * base * power(base, exponent - 1, modulo) % modulo;
    int half = power(base, exponent >> 1, modulo);
    return 1LL * half * half % modulo;
}
int inverse(int value, int modulo = MODULO) {
    return power(value, modulo - 2, modulo);
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N;
    const int INV24 = inverse(24, MODULO);
    
    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> N;
        int lhs = 1LL * (N - 1) * N / 2 % MODULO;
        int rhs = INV24;
        for (int i = 0; i < 4; i ++) {
            rhs = 1LL * rhs * (N - i) % MODULO;
        }
        cout << "Case " << c + 1 << ": " << (lhs + rhs + 1) % MODULO << endl;
    }
    
    return 0;
}

