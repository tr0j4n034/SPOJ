//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 100005;

int N;
int f[MAX];
vector<int> divisors[MAX];

int main() {
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }
    for (int i = 3; i <= N; i ++) {
        if ((int)divisors[i].size() == 2) {
            f[i] = 0;
        }
        else {
            f[i] = 1 << 30;
            int best = 1 << 30, bestSum = 1 << 30;
            for (int j : divisors[i]) {
                if (j + i / j < bestSum) {
                    best = j;
                    bestSum = j + i /j;
                }
            }
            f[i] = f[best] + f[i / best];
        }
    }
    cout << f[N] << endl;
    
    return 0;
}
