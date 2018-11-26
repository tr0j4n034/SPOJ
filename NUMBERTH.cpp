//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/26/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(T * N! * N^2) solution
 Almost bruteforcing but since the length of the strings are very small,
    this methods is usable here...
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int S = 1 << 24;

int T, N;
string s;
int prime[S], onUse[S], active[S];

int main() {
    prime[1] = 1;
    for (int i = 2; i * i < S; i ++) {
        if (prime[i]) {
            continue;
        } for (int j = i * i; j < S; j += i) {
            prime[j] = 1;
        }
    }
    
    cin >> T;
    while (T --) {
        cin >> s;
        int L = (int)s.size();
        N = 0;
        sort(s.begin(), s.end());
        do {
            for (int i = 0; i < L; i ++) {
                if (s[i] == '0') {
                    continue;
                }
                int x = 0;
                for (int j = i; j < L; j ++) {
                    x = 10 * x + s[j] - '0';
                    if (!prime[x] && !onUse[x]) {
                        active[N ++] = x;
                        onUse[x] = 1;
                    }
                }
            }
        } while(next_permutation(s.begin(), s.end()));
        for (int i = 0; i < N; i ++) {
            onUse[active[i]] = 0;
        }
        cout << N << endl;
    }
    
    
    return 0;
}

