//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/8/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Please, write/copy-paste Miller-Rabin for primality test of the input numbers
 Overall complexity O(T * N^(1/3)) if you use Miller-Rabin or some other primality test...
 */

#pragma GCC optimize("-0g")

#include <iostream>

using namespace std;

const int S = 1 << 22;
const int MODULO = 1000000007;

int T, K, primeCount;
long long N;
int lp[S], primelist[S];

int power(int a, int b, int modulo = MODULO) {
    int result = 1, p = a;
    while (b) {
        if (b & 1) {
            result = 1LL * result * p % modulo;
        }
        b >>= 1;
        p = 1LL * p * p % modulo;
    }
    return result;
}
int inverse(int a, int modulo = MODULO) {
    return power(a, modulo - 2);
}

int main() {
    for(int i = 2; i < S; i ++){
        if(!lp[i]){
            primelist[++primeCount] = i;
            lp[i] = i;
        }
        for(int j = 1; j <= primeCount && primelist[j] <= lp[i] && i * primelist[j] < S; j ++)
            lp[i * primelist[j]] = primelist[j];
    }
    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> N >> K;
        int result = 1;
        int invProduct = 1;
        for (int i = 1; i <= primeCount; i ++) {
            if (1LL * primelist[i] * primelist[i] > N) {
                break;
            }
            if (N % primelist[i] == 0) {
                int d = 0;
                while (N % primelist[i] == 0) {
                    d ++;
                    N /= primelist[i];
                }
                int base = power(primelist[i], K);
                int numerator = power(base, d + 1) - 1;
                invProduct = 1LL * invProduct * (base - 1) % MODULO;
                result = 1LL * result * numerator % MODULO;
            }
        }
        if (N > 1) {
            int base = power(N % MODULO, K);
            int numerator = 1LL * base * base % MODULO - 1;
            invProduct = 1LL * invProduct * (base - 1) % MODULO;
            result = 1LL * result * numerator % MODULO;
        }
        result = 1LL * result * inverse(invProduct) % MODULO;
        cout << "Case " << c + 1 << ": " << result << endl;
        cout << endl;
    }
    
    return 0;
}
