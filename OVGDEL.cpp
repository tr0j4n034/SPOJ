//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/17/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int S = 1000005;

int T, N;
int a[S];
int counts[S];

int main() {
    scanf("%d", &T);
    for (int _ = 0; _ < T; _ ++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
            counts[a[i]] ++;
        }
        int result = 0;
        for (int i = 1; i <= N; i ++) {
            for (long long p = 1; p < S; p *= a[i]) {
                if (counts[p] > (int)(p == a[i])) {
                    result ++;
                    break;
                }
                if (a[i] == 1) break;
            }
        }
        for (int i = 1; i <= N; i ++) {
            counts[a[i]] --;
        }
        printf("Case %d: %d\n", _ + 1, result);
    }
    
    return 0;
}

