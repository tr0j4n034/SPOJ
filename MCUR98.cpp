//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/2/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

const int MAX = 1000000;

int f[MAX], sum[MAX];

int main(int argc, const char * argv[]) {
    for (int i = 1; i < MAX; i ++) {
        sum[i] = sum[i / 10] + i % 10;
        for (int j = max(i - 60, 1); j < i; j ++) {
            if (sum[j] == i - j) {
                f[i] = 1;
                break;
            }
        }
        if (!f[i]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
