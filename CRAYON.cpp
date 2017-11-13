//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * log(N)) solution using Fenwick trees.
 In order to avoid large numbers, you may compress all the query data.
 And instead of counting the number of intersecting segments, just
  try to subtract nonintersecting segments.
 For example, if we need to count the number of segments intersecting with
  current query range [l, r]
 we need to subtract:
  segments having left endpoint larger than r
 and
  segment having right endpoint less than l.
 This part can be efficiently done with Fenwick trees or segment trees.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1000005;

int N;
int segmentID;
char ch;
char type[MAX];
int l[MAX], r[MAX], who[MAX], c[MAX];
int ftree[2][MAX]; // 0 --> left, 1 --> right
vector<int> data;

void add(int *ft, int position, int value) {
    for ( ; position < MAX; position += (position & -position)) {
        ft[position] += value;
    }
}
int get(int *ft, int position) {
    int sum = 0;
    for ( ; position > 0; position -= (position & -position)) {
        sum += ft[position];
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i ++) {
        scanf(" %c", &type[i]);
        if (type[i] == 'C') { // clear
            scanf("%d", &c[i]);
        }
        else if (type[i] == 'D') { // draw
            scanf("%d%d", &l[i], &r[i]);
            who[++segmentID] = i;
        }
        else { // query
            scanf("%d%d", &l[i], &r[i]);
        }
    }
    
    data = vector<int>(l, l + N);
    data.insert(data.end(), r, r + N);
    sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());
    for (int i = 0; i < N; i ++) {
        if (type[i] != 'C') {
            l[i] = (int)(lower_bound(data.begin(), data.end(), l[i]) - data.begin());
            r[i] = (int)(lower_bound(data.begin(), data.end(), r[i]) - data.begin());
        }
    }
    
    int active = 0;
    for (int i = 0; i < N; i ++) {
        if (type[i] == 'D') {
            add(ftree[0], l[i], 1);
            add(ftree[1], r[i], 1);
            active ++;
        }
        else if (type[i] == 'C') {
            int id = who[c[i]];
            add(ftree[0], l[id], -1);
            add(ftree[1], r[id], -1);
            active --;
        }
        else {
            printf("%d\n", get(ftree[0], r[i]) - get(ftree[1], l[i] - 1));
        }
    }
    
    return 0;
}
