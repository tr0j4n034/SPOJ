//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/26/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1000005;
const int modulo = 1000000007;

int T, N;
int f[MAX];

int main() {
    f[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        f[i] = 1LL * (i - 1) * (f[i - 1] + f[i - 2]) % modulo;
    }
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        printf("%d\n", f[N]);
    }
    
    return 0;
}
