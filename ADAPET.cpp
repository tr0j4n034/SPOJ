//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/07/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * (total_length_of_input_strings)) solution
 Basically, you need to find the longest suffix
  which is also a prefix of the input string.
 This can be done KMP like structures and hashing in O(N).
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mods[] = {715225741, 1000000007};
const int muls[] = {43, 73};

const int MAX = 500005;

int T, N, K;
char ch;
char data[MAX];
int powers[2][MAX], prefix[2][MAX], suffix[2][MAX];

int main() {
    powers[0][0] = powers[1][0] = 1;
    for (int i = 0; i < 2; i ++) {
        for (int j = 1; j < MAX; j ++) powers[i][j] = 1LL * powers[i][j - 1] * muls[i] % mods[i];
    }
    
    scanf("%d", &T);
    while (T --) {
        N = 0;
        getchar_unlocked();
        while ((ch = getchar_unlocked()) != ' ') {
            data[++N] = ch;
        }
        scanf("%d", &K);
        
        for (int i = 0; i < 2; i ++) {
            prefix[i][0] = 0;
            for (int j = 1; j <= N; j ++) {
                prefix[i][j] = (1LL * prefix[i][j - 1] * muls[i] % mods[i] + data[j]) % mods[i];
            }
        }
        for (int i = 0; i < 2; i ++) {
            suffix[i][N + 1] = 0;
            for (int j = N; j > 0; j --) {
                suffix[i][j] = (1LL * powers[i][N - j] * data[j] % mods[i] + suffix[i][j + 1]) % mods[i];
            }
        }
        int bestSuffix = 0;
        for (int i = N - 1; i > 0; i --) {
            if (prefix[0][i] == suffix[0][N - i + 1] && prefix[1][i] == suffix[1][N - i + 1]) {
                bestSuffix = i;
                break;
            }
        }
        printf("%lld\n", N + 1LL * (K - 1) * (N - bestSuffix));
    }
    
    return 0;
}
