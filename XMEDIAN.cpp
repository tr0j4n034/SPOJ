//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/12/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * log^2(N)) solution using Fenwick trees + Binary Search
 Actually, the problem can be solved in O(N * log(N)) with ordered data structures.
 */

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int MAX = 1000005;

int N;
int ftree[MAX];

void add(int position, int value) {
    for ( ; position < MAX; position += (position & -position)) ftree[position] += value;
}
int get(int position) {
    int sum = 0;
    for ( ; position > 0; position -= (position & -position)) sum += ftree[position];
    return sum;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        int value;
        scanf("%d", &value);
        add(value, 1);
        int best = 0, current = 0;
        for (int j = (1 << 20); j > 0; j >>= 1) {
            if (current + j > MAX) continue;
            int s = get(current + j);
            if (s >= (i + 1) / 2) {
                best = current + j;
            }
            else {
                current += j;
            }
        }
        printf("%d\n", best);
    }
    
    return 0;
}
