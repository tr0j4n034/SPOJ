//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/16/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10005;

int T, N, M;
int period[MAX];

int main(int argc, const char * argv[]) {
    cin >> T;
    while (T --) {
        cin >> N >> M;
        for (int i = 1; i <= N; i ++) {
            cin >> period[i];
        }
        long long low = 0, high = 1LL << 62, best = high;
        while (low <= high) {
            long long middle = (low + high + 1) >> 1;
            long long can = 0;
            for (int i = 1; i <= N && can < M; i ++) {
                can += middle / period[i];
            }
            if (can >= M) {
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
