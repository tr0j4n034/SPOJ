//
//  main.cpp
//  practice
//
//  Created by Mahmud on 24/07/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
    int T, N;
    
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        priority_queue<long long, vector<long long>, greater<long long> > Q;
        for (int i = 0; i < N; i ++) {
            int x;
            scanf("%d", &x);
            Q.push(x);
        }
        long long cost = 0;
        while (Q.size() > 1) {
            long long a = Q.top();
            Q.pop();
            long long b = Q.top();
            Q.pop();
            Q.push(a + b);
            cost += a + b;
        }
        printf("%lld\n", cost);
    }

    return 0;
}
