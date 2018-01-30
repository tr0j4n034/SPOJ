//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/30/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * K * log(N)) solution based on Fenwick trees
 The problem can be solved in similar way to INCSEQ.
 In order to not to count the same subsequences multiple times,
  subtract previous values during each pass.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

const int MAX = 10005;
const int SIZE = 51;
const int MODULO = 5000000;

int N, K;
int data[MAX];
int ftree[SIZE][MAX], dp[SIZE][MAX];
int lastOccurence[MAX];

void add(int *ftree, int position, int value) {
    for ( ; position <= N; position += (position & -position)) {
        ftree[position] = (ftree[position] + value) % MODULO;
    }
}
int get(int *ftree, int position) {
    int sum = 0;
    for ( ; position > 0; position -= (position & -position)) {
        sum = (sum + ftree[position]) % MODULO;
    }
    return sum;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i ++) scanf("%d", &data[i]);
    
    function<void(int *)> compress = [](int *data) {
        vector<int> values = vector<int>(data + 1, data + N + 1);
        sort(values.begin(), values.end());
        for (int i = 1; i <= N; i ++) {
            data[i] = (int)(lower_bound(values.begin(), values.end(), data[i]) - values.begin()) + 1;
        }
    };
    compress(data);
    
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= K; j ++) {
            int currentSum = ((j > 1 ? get(ftree[j - 1], data[i] - 1) : 1) - dp[j][data[i]] + MODULO) % MODULO;
            add(ftree[j], data[i], currentSum);
            dp[j][data[i]] = (dp[j][data[i]] + currentSum) % MODULO;
        }
    }
    cout << get(ftree[K], N) << endl;
    
    return 0;
}
