//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/17/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

const int S = 100005;

int T, N;
pair<int, int> data[S];

int main() {
    scanf("%d", &T);
    for (int _ = 0; _ < T; _ ++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &data[i].first);
            data[i].second = i;
        }
        sort(data + 1, data + N + 1);
        int result = -1;
        if (N & 1) {
            result = data[(N >> 1) + 1].second;
        }
        else {
            result = min(data[N >> 1].second, data[(N >> 1) + 1].second);
        }
        printf("Case %d: %d\n", _ + 1, result);
    }
    
    return 0;
}

