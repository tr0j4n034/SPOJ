//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int T, A, B, N;
    
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%d", &A, &B, &N);
        long long low = 1, high = 1LL << 60, middle, best = high;
        int lcm = A * B / __gcd(A, B);
        while (low <= high) {
            middle = (low + high + 1) >> 1;
            long long order = middle / A + middle / B - middle / lcm;
            if (order >= N) {
                best = middle;
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }
        printf("%lld\n", best);
    }
    
    return 0;
}
