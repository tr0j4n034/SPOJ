//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/14/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * 2^N) solution using bitmask technique
 Just calculate sum of values for each mask...
 */

#include <iostream>

using namespace std;

const int MAX = 20;

int T, N;
long long M;
long long data[MAX], sumMask[1 << MAX];

int main() {
    cin >> T;
    while (T --) {
        cin >> N >> M;
        for (int i = 0; i < N; i ++) cin >> data[i];
        for (int i = 0; i < (1 << N); i ++) {
            for (int j = 0; j < N; j ++) {
                if (i & (1 << j)) {
                    sumMask[i] = sumMask[i ^ (1 << j)] + data[j];
                    break;
                }
            }
        }
        long long best = 0;
        for (int i = 0; i < (1 << N); i ++) {
            if (sumMask[i] <= M && sumMask[i] >= best) best = sumMask[i];
        }
        cout << best << endl;
    }
    
    return 0;
}
