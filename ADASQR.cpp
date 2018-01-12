//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/12/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N^2) solution heavily based on precomputation techniques
 Due to the huge input, O(N^2 * log(N)) solutions do not pass even there are plenty of optimizations done.
 Firstly, we need to somehow multiply two 64-bit numbers under modulo another 64-bit integer.
 Instead of fast binary powering algorithm (which has complexity O(log(N))),
  we can use double-s to multiply those numbers.
 Secondly, precomputation is required to find minimum element for each of subarray of any particular rows
  in O(1). This part can be done using deques.
 Remaining part is like 2-pointers method, and easy to handle.
 */

#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

const int MAX = 5005;
const int MODULO = 1000000007;

long long multiply(long long a, long long b, long long modulo) {
    long long q = (long double)a * (long double)b / (long double)modulo;
    long long result = a * b - q * modulo;
    return (result + (modulo << 2)) % modulo;
}

int N, K;
long long data[MAX][MAX];
long long minimumInRow[MAX][MAX];

void add(deque<long long> &dq, long long value) {
    while (!dq.empty() && dq.back() > value) dq.pop_back();
    dq.push_back(value);
}
void remove(deque<long long> &dq, long long value) {
    if (!dq.empty() && dq.front() == value) dq.pop_front();
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i ++) {
        long long x0, a, b, c;
        scanf("%lld%lld%lld%lld", &x0, &a, &b, &c);
        data[i][1] = x0;
        a %= c;
        b %= c;
        for (int j = 2; j <= N; j ++) {
            data[i][j] = (multiply(data[i][j - 1], a, c) + b) % c;
        }
    }
    //    for (int i = 1; i <= N; i ++) {
    //        cerr << "row i = " << i << " contains: ";
    //        for (int j = 1; j <= N; j ++) cout << data[i][j] << " ";
    //        cout << endl;
    //    }
    // precalculating minimums for rows
    for (int i = 1; i <= N; i ++) {
        deque<long long> activeMinimums;
        for (int j = 1; j <= N; j ++) {
            if (j > K) remove(activeMinimums, data[i][j - K]);
            add(activeMinimums, data[i][j]);
            minimumInRow[i][j] = activeMinimums.front();
        }
    }
    //    for (int i = 1; i <= N; i ++) {
    //        cerr << "minimums in row i = " << i << " are: ";
    //        for (int j = 1; j <= N; j ++) cout << minimumInRow[i][j] << " ";
    //        cout << endl;
    //    }
    long long result = 0;
    for (int j = K; j <= N; j ++) {
        deque<long long> activeMinimums;
        for (int i = 1; i <= N; i ++) {
            if (i > K) remove(activeMinimums, minimumInRow[i - K][j]);
            add(activeMinimums, minimumInRow[i][j]);
            if (i >= K) result = (result + activeMinimums.front()) % MODULO;
        }
    }
    printf("%lld\n", result);
    
    return 0;
}

