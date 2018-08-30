//
//  main.cpp
//  practice
//
//  Created by Mahmud on 30/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 The key observation is that if there exists an element with count more than 1,
    the answer is YES.
 Otherwise, we have at most 1 + 2 + ... + 100 elements in total,
    so that you can use classical dp approach for knapsack problem.
 */

#include <iostream>

using namespace std;

const int MAX_VALUE = 100;
const int KNAPSACK_SIZE = MAX_VALUE << 6;

int T, N;
int counts[MAX_VALUE + 1];
int ways[KNAPSACK_SIZE + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T --) {
        cin >> N;
        for (int i = 1; i <= MAX_VALUE; i ++) {
            counts[i] = 0;
        } for (int i = 1; i <= KNAPSACK_SIZE; i ++) {
            ways[i] = 0;
        } for (int i = 1; i <= N; i ++) {
            int value;
            cin >> value;
            counts[value] ++;
        }
        bool can = false;
        for (int i = 1; i <= MAX_VALUE && !can; i ++) {
            if (counts[i] > 1) {
                can = true;
            }
        }
        ways[0] = 1;
        for (int i = 1; i <= MAX_VALUE && !can; i ++) {
            if (!counts[i]) {
                continue;
            } for (int j = KNAPSACK_SIZE; j >= i && !can; j --) {
                ways[j] += ways[j - i];
                if (ways[j] > 1) {
                    can = true;
                }
            }
        }
        if (can) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

