//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/29/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 You can either do some math,
    or precalculate the results for smaller values and go to oeis...
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_SIZE = 1 << 17;
const int MODULO = 1000000007;

int T, N;
int powers[MAX_SIZE];

int main(int argc, const char * argv[]) {
    powers[0] = 1;
    for (int i = 1; i < MAX_SIZE; i ++) {
        powers[i] = powers[i - 1] * 2 % MODULO;
    }
    scanf("%d", &T);
    for (int c = 0; c < T; c ++) {
        scanf("%d", &N);
        printf("Case %d: %d\n", c + 1, N == 1 ? 1 : (int)(1LL * (N + 1) * powers[N - 2] % MODULO));
    }
    
    return 0;
}

