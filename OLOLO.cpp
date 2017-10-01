//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/1/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>

using namespace std;

int N, x, result;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i ++) {
        scanf("%d", &x);
        result ^= x;
    }
    printf("%d\n", result);
    
    return 0;
}

