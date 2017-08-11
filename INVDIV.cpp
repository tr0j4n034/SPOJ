//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/11/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 Use multiplicative property of sigma function
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 100000025;

int T, N;
int sigma[MAX], psigma[MAX];
int lp[MAX], p[MAX], pc[MAX];

int main(int argc, const char * argv[]) {
    for (int i = 2; i< MAX; i ++) {
        if (!lp[i]) {
            for (int j = i; j < MAX; j += i) {
                if (!lp[j]) {
                    lp[j] = i;
                }
            }
        }
    }
    sigma[1] = 1;
    psigma[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        int j = i / lp[i];
        if (j % lp[i] == 0) {
            p[i] = p[j];
            if (pc[j] > MAX / lp[i]) {
                continue;
            }
            pc[i] = pc[j] * lp[i];
        }
        else {
            p[i] = j;
            pc[i] = lp[i];
        }
        long long v = 1LL * sigma[p[i]] * ((1LL * pc[i] * lp[i] - 1) / (lp[i] - 1));
        if (v < MAX) {
            sigma[i] = (int)v;
            if (psigma[v] == 0) {
                psigma[v] = i;
            }
        }
    }
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        if (psigma[N] == 0) {
            puts("-1");
        }
        else {
            printf("%d\n", psigma[N]);
        }
    }
    
    return 0;
}
