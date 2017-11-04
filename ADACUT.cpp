//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/30/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 A simple O(N * log(N)) solution.
 Of course, the answer is equal to one of the input elements.
 First, sort the input.
 Now, think this way: If we choose current element as the required height for, what will happen
  to other elements of the array?
 Smaller elements need to be removed(cut down those trees), and bigger elements need
  to be reduced to current height.
 This part can be efficiently handled by using prefix sum technique.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 300005;

int N;
int data[MAX];
long long prefix[MAX];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &data[i]);
    }
    sort(data + 1, data + N + 1);
    for (int i = 1; i <= N; i ++) {
        prefix[i] = prefix[i - 1] + data[i];
    }
    long long result = 1LL << 55, all = prefix[N];
    for (int i = 1; i <= N; i ++) {
        result = min(result, all - 1LL * (N - i + 1) * data[i]);
    }
    printf("%lld\n", result);
    
    return 0;
}
