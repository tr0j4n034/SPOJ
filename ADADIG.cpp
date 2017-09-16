//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/16/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 A simple recursive solution
 The main point is that we can not use more than log2(N) digits which are not equal to 1.
 So we just need to consider the possible combinations of digits between 2 and 9.
 And the rest will be ones.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 300005;
const int modulo = 1000000007;

int T, N;
int result;
int fac[MAX];

int binaryPower (int a, int b, int modulo) {
    if (b == 0) {
        return 1 % modulo;
    }
    if (b & 1) {
        return 1LL * binaryPower(a, b - 1, modulo) * a % modulo;
    }
    int half = binaryPower(a, b >> 1, modulo);
    return 1LL * half * half % modulo;
}
int inverse (int a, int modulo) {
    return binaryPower(a, modulo - 2, modulo);
}
void go (int digit, int product, int sum, int takenDigits, int denominator) {
    if (sum > N) {
        return;
    }
    if (product == 1) {
        int ones = N - sum;
        int numerator = fac[takenDigits + ones];
        denominator = 1LL * denominator * fac[ones] % modulo;
        result = (result + 1LL * numerator * inverse(denominator, modulo) % modulo) % modulo;
        return;
    }
    if (digit > 9) {
        return;
    }
    go(digit + 1, product, sum, takenDigits, denominator);
    int count = 0;
    while (product % digit == 0) {
        count ++;
        product /= digit;
        go(digit + 1, product, sum + digit * count, takenDigits + count, 1LL * denominator * fac[count] % modulo);
    }
}


int main(int argc, const char * argv[]) {
    fac[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        fac[i] = 1LL * fac[i - 1] * i % modulo;
    }
    
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        result = 0;
        go(2, N, 0, 0, 1);
        printf("%d\n", result);
    }
    
    return 0;
}
