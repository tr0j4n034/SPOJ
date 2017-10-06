//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/6/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 The first observation is that the number of "protean" numbers of length N
 is just equal to N-th Fibonacci number.
 Then we process the input strings starting from the most significant bit.
 If current bit is 0, skip it.
 Else we add fibonacci[remaining_digits + 1] to our answer.
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 95;

int T;
string s;
long long f[MAX];

int main() {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i < MAX; i ++) {
        f[i] = f[i - 2] + f[i - 1];
    }
    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> s;
        int length = (int)s.size();
        long long result = 0;
        for (int i = 1; i < length; i ++) {
            result += f[i];
        }
        for (int i = 1; i < length; i ++) {
            if (s[i] == '1') {
                result += f[length - i + 1];
            }
        }
        printf("Case %d: %lld\n", c + 1, result + 1);
    }
    
    return 0;
}
