//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N) solution using dynamic programming.
 Consider what happens when we add a single character to the current string.
 We can skip current letter or add it to all of previous available strings:
  So dp[i] = 2 * dp[i - 1].
 And we need to subtract repeating substrings whci can be found at the position where
  current character occured last.
 */

#include <iostream>

using namespace std;

const int MAX = 100005;
const int MODULO = 1000000007;

int T;
char ch;
int dp[MAX], was[MAX];

int main() {
    scanf("%d", &T);
    getchar();
    while (T --) {
        for (int i = 'A'; i <= 'Z'; i ++) {
            was[i] = -1;
        }
        dp[0] = 1;
        int length = 0;
        for ( ; (ch = getchar()) != '\n'; ) {
            ++length;
            dp[length] = (dp[length - 1] << 1) % MODULO;
            if (was[ch] != -1) {
                dp[length] = (dp[length] - dp[was[ch] - 1] + MODULO) % MODULO;
            }
            was[ch] = length;
        }
        printf("%d\n", dp[length]);
    }
    
    return 0;
}
