//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/09/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10000005;

int T, N;
int lp[MAX], delta[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) lp[j] = i;
    }
    for (int i = 2; i < MAX; i ++) {
        int j = i, cnt = 0;
        while (j % lp[i] == 0) {
            j /= lp[i];
            cnt ^= 1;
        }
        delta[i] = delta[j] + (cnt ? -1 : 1);
    }
    
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        if (delta[N] > 0) puts("Psycho Number");
        else puts("Ordinary Number");
    }
    
    return 0;
}
