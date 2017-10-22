//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/22/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N^2) solution using memoization (dynamic programming)
 Except base cases, we have only 2 choices.
 Just handle these cases in recursion.
 */


#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 2005;

int N;
int cost[MAX], dp[MAX][MAX];

int calculate(int low, int high) {
    if (dp[low][high] != -1) {
        return dp[low][high];
    }
    if (low == high) {
        return dp[low][high] = N * cost[low];
    }
    int &result = dp[low][high];
    result = max(result, calculate(low, high - 1) + (low + N - high) * cost[high]);
    result = max(result, calculate(low + 1, high) + (low + N - high) * cost[low]);
    return result;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        cin >> cost[i];
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = i; j <= N; j ++) {
            dp[i][j] = -1;
        }
    }
    cout << calculate(1, N) << endl;
    
    return 0;
}
