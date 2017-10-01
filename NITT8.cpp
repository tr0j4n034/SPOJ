//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/1/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 An O(T * N * log(N)) solution
 We just need to calculate the leftmost element which is not less than current element.
 Although it can be done by using stacks, this N*log(N) solution is a bit more intuitive.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX = 100005;

int T, N;
pair<int, int> data[MAX], temp[MAX];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &data[i].first);
            data[i].second = i;
            temp[i] = data[i];
        }
        long long result = 0;
        for (int _ = 0; _ < 2; _ ++) {
            for (int i = 1; i <= N; i ++) {
                data[i] = temp[i];
            }
            for (int i = 1; i <= N; i ++) {
                temp[i].second = N + 1 - temp[i].second;
            }
            sort(data + 1, data + N + 1, [&](pair<int, int> a, pair<int, int> b) {
                if (a.first != b.first) {
                    return a.first < b.first;
                }
                return a.second > b.second;
            });
            
            int leftmostIndex = N + 1;
            for (int i = N; i > 0; i --) {
                result = max(result, 1LL * data[i].first * (data[i].second - leftmostIndex));
                leftmostIndex = min(leftmostIndex, data[i].second);
            }
        }
        cout << result << endl;
    }
    
    return 0;
}

