//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O((N + Q) * log(N)) solution using lazy segment trees
 In order to keep track of each element,
  you can use two arrays:
   first one to find where is the element numbered "i".
   second one to to find what is real index of each element in segment tree.
 These precomputations can be done by sorting input elements at the beginning.
 Finding lower bound can be done in O(log(N)) by branching left or right child every time.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 100005;

int N, Q;
int positionOfData[MAX], whoIs[MAX];
pair<int, int> data[MAX];

int type, x;
int stree[MAX << 2], lazy[MAX << 2];

void build(int I, int low, int high) {
    if (low == high) {
        stree[I] = data[low].first;
        return;
    }
    int middle = (low + high) >> 1;
    build(I << 1, low, middle);
    build(I << 1 | 1, middle + 1, high);
    stree[I] = max(stree[I << 1], stree[I << 1 | 1]);
}
void push(int I, int low, int high) {
    if (lazy[I]) {
        stree[I] += lazy[I];
        if (low != high) {
            lazy[I << 1] += lazy[I];
            lazy[I << 1 | 1] += lazy[I];
        }
        lazy[I] = 0;
    }
}
void add(int I, int low, int high, int l, int r, int value) {
    push(I, low, high);
    if (low > r || high < l) return;
    if (low >= l && high <= r) {
        lazy[I] += value;
        push(I, low, high);
        return;
    }
    int middle = (low + high) >> 1;
    add(I << 1, low, middle, l, r, value);
    add(I << 1 | 1, middle + 1, high, l, r, value);
    stree[I] = max(stree[I << 1], stree[I << 1 | 1]);
}
int getElement(int I, int low, int high, int position) {
    push(I, low, high);
    if (low == high) return stree[I];
    int middle = (low + high) >> 1;
    if (position <= middle) return getElement(I << 1, low, middle, position);
    else return getElement(I << 1 | 1, middle + 1, high, position);
}
int lowerBound(int I, int low, int high, int value) {
    push(I, low, high);
    if (stree[I] < value) return high + 1;
    if (low == high) return low;
    int middle = (low + high) >> 1;
    push(I << 1, low, middle);
    push(I << 1 | 1, middle + 1, high);
    if (stree[I << 1] >= value) return lowerBound(I << 1, low, middle, value);
    else return lowerBound(I << 1 | 1, middle + 1, high, value);
}
int upperBound(int I, int low, int high, int value) {
    return lowerBound(I, low, high, value + 1);
}

int main() {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &data[i].first);
        data[i].second = i;
    }
    sort(data + 1, data + N + 1);
    for (int i = 1; i <= N; i ++) {
        positionOfData[data[i].second] = i;
        whoIs[i] = data[i].second;
    }
    //    for (int i = 1; i <= N; i ++) {
    //        cout << i << " vs " << whoIs[i] << " and " << positionOfData[i] << endl;
    //        // who is in ith position
    //        // real position of ith element
    //    }
    build(1, 1, N);
    while (Q --) {
        scanf("%d%d", &type, &x);
        if (type == 1) {
            int previousID = x;
            int previousPosition = positionOfData[x];
            int previousValue = getElement(1, 1, N, previousPosition);
            int currentPosition = upperBound(1, 1, N, previousValue) - 1;
            int currentID = whoIs[currentPosition];
            if (previousID == currentID) {
                add(1, 1, N, previousPosition, previousPosition, +1);
            }
            else {
                swap(positionOfData[previousID], positionOfData[currentID]);
                swap(whoIs[previousPosition], whoIs[currentPosition]);
                add(1, 1, N, currentPosition, currentPosition, +1);
            }
        }
        else if (type == 2) {
            printf("%d\n", N - lowerBound(1, 1, N, x) + 1);
        }
        else {
            int lb = lowerBound(1, 1, N, x);
            if (lb != N + 1) add(1, 1, N, lb, N, -1);
        }
    }
    
    return 0;
}
