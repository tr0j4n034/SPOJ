//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/1/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX = 105;

int T, N;
int length = 0;
int output[MAX];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        if (N == 0) {
            puts("10");
            continue;
        }
        length = 0;
        for (int i = 9; i > 1; i --) {
            while (N % i == 0) {
                output[length ++] = i;
                N /= i;
            }
        }
        if (N != 1) {
            puts("-1");
        }
        else {
            for (int i = length - 1; i >= 0; i --) {
                printf("%d", output[i]);
            }
            putchar('\n');
        }
    }
    
    return 0;
}

