//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/20/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10005;

int T, N;

int main() {
    scanf("%d", &T);
    while(T --) {
        scanf("%d", &N);
        long long sum = 0, data;
        for (int i = 1; i <= N; i ++) {
            scanf("%lld", &data);
            sum += data % N;
        }
        if (sum % N) {
            puts("NO");
        }
        else {
            puts("YES");
        }
    }
    
    return 0;
}
