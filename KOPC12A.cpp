//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

const int MAX = 10005;

int T, N;
int height[MAX], cost[MAX];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) scanf("%d", &height[i]);
        for (int i = 1; i <= N; i ++) scanf("%d", &cost[i]);
        
        auto f = [](int h) {
            long long sum = 0;
            for (int i = 1; i <= N; i ++) {
                sum += 1LL * cost[i] * abs(height[i] - h);
            }
            return sum;
        };
        int low = 0, high = 10000;
        while (low < high) {
            int middle = (low + high) >> 1;
            if (f(middle) < f(middle + 1)) {
                high = middle;
            }
            else {
                low = middle + 1;
            }
        }
        cout << min(f(low), f(low + 1)) << endl;
    }
    
    return 0;
}
