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

const int MAX = 100005;

int T, N;
int data[MAX], counts[MAX];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) scanf("%d", &data[i]);
        long long sum = 0;
        for (int i = 1; i <= N; i ++) sum += data[i];
        if (sum % N == 0) printf("%d\n", N);
        else printf("%d\n", N - 1);
    }
    
    return 0;
}
