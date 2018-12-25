//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/25/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(N * log(N)) solution
 Consider adding a new element after i-th index:
    how can we find the best matching on the right part of the array?
 It can be done by preprocessing all the suffixes beforehand in O(N * log(N))...
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <utility>

using namespace std;

const int MAX_SIZE = 1 << 20;

int N;
int data[MAX_SIZE];
int leftDP[MAX_SIZE], rightDP[MAX_SIZE];
int stamp[MAX_SIZE];

int main(int argc, const char * argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &data[i]);
    }
    multiset<pair<int, int>> active;
    for (int i = N; i > 0; i --) {
        rightDP[data[i]] = rightDP[data[i] + 1] + 1;
        stamp[i] = rightDP[data[i]];
        active.insert(make_pair(data[i], stamp[i]));
    }
    active.insert(make_pair(-1, -1));
    
    int result = 0;
    for (int i = 1; i <= N; i ++) {
        leftDP[data[i]] = leftDP[data[i] - 1] + 1;
        auto it = --active.lower_bound(make_pair(data[i] + 3, 0));
        if ((*it).first == data[i] + 2) {
            result = max(result, leftDP[data[i]] + 1 + (*it).second);
        }
        result = max(result, leftDP[data[i]] + 1);
        active.erase(active.find(make_pair(data[i], stamp[i])));
    }
    printf("%d\n", result);
    
    return 0;
}

