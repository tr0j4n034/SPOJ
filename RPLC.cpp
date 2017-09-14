//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/15/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int T, N, x;
    scanf("%d", &T);
    for (int c = 0; c < T; c ++) {
        scanf("%d", &N);
        long long prefix = 0, minimum = 0;
        for (int i = 0; i < N; i ++) {
            scanf("%d", &x);
            prefix += x;
            if (prefix < minimum) {
                minimum = prefix;
            }
        }
        printf("Scenario #%d: %lld\n", c + 1, -minimum + 1);
    }
    
    return 0;
}
