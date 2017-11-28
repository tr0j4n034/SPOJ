//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/28/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 An iterative O(N) solution to Josephus problem
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int N, D;
    while (scanf("%d%d", &N, &D)) {
        if (N + D == 0) break;
        int position = 1;
        for (int i = 1; i <= N; i ++) position = (position + D) % i;
        printf("%d %d %d\n", N, D, position + 1);
    }
    
    return 0;
}
