//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>

using namespace std;

int T;
long long N;
int pows[15];

int main() {
    pows[0] = 1;
    for (int i = 1; i < 11; i ++) {
        pows[i] = pows[i - 1] * 34 % 11;
    }
    scanf("%d", &T);
    while (T --) {
        scanf("%lld", &N);
        int f = (pows[N % 10] + 8 * (N % 11) + 10) % 11;
        printf("%d\n", f == 0 ? 0 : 11 - f);
    }
    
    return 0;
}
