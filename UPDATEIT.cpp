//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/24/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int T, N, M, Q;

int main(int argc, const char * argv[]) {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &M);
        vector<int> data(N, 0);
        for (int i = 0; i < M; i ++) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            data[l] += x;
            if (r < N - 1) {
                data[r + 1] -= x;
            }
        }
        for (int i = 1; i < N; i ++) {
            data[i] += data[i - 1];
        }
        scanf("%d", &Q);
        while (Q --) {
            int position;
            scanf("%d", &position);
            printf("%d\n", data[position]);
        }
    }
    
    return 0;
}
