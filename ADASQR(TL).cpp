//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/14/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int MAX = 5005;
const int modulo = 1000000007;

long long multiply(long long a, long long b, long long modulo) {
    if (b == 0) {
        return 0;
    }
    long long half = multiply(a, b >> 1, modulo);
    return ((half << 1) % modulo + ((b & 1) ? a : 0)) % modulo;
}

int N, K;
long long x0, a, b, c;
long long table[MAX][MAX];
long long f[MAX];
multiset<long long> columns[MAX];

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i ++) {
        scanf("%lld%lld%lld%lld", &x0, &a, &b, &c);
        table[i][1] = x0;
        for (int j = 2; j <= N; j ++) {
            table[i][j] = (multiply(table[i][j - 1] % c, a, c) + b) % c;
        }
    }
    long long result = 0;
    for (int i = 1; i < K; i ++) {
        for (int j = 1; j <= N; j ++) {
            columns[j].insert(table[i][j]);
        }
    }
    for (int i = K; i <= N; i ++) {
        if (i > K) {
            for (int j = 1; j <= N; j ++) {
                columns[j].erase(columns[j].find(table[i - K][j]));
            }
        }
        for (int j = 1; j <= N; j ++) {
            columns[j].insert(table[i][j]);
        }
        multiset<long long> data;
        for (int j = 1; j <= K; j ++) {
            f[j] = *columns[j].begin();
            data.insert(f[j]);
        }
        result = (result + (*data.begin())) % modulo;
        for (int j = K + 1; j <= N; j ++) {
            data.erase(data.find(f[j - K]));
            f[j] = *columns[j].begin();
            data.insert(f[j]);
            result = (result + (*data.begin())) % modulo;
        }
    }
    cout << result << endl;
    
    return 0;
}

