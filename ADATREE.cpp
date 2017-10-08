//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/8/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 300005;

int N, Q;
int data[MAX];
vector<int> stree[MAX << 2];

void merge(vector<int> &a, vector<int> &b, vector<int> &to) {
    int lengthA = (int)a.size();
    int lengthB = (int)b.size();
    int ptrA = 0, ptrB = 0;
    while (ptrA < lengthA && ptrB < lengthB) {
        if (a[ptrA] < b[ptrB]) {
            to.push_back(a[ptrA]);
            ptrA ++;
        }
        else {
            to.push_back(b[ptrB]);
            ptrB ++;
        }
    }
    while (ptrA < lengthA) {
        to.push_back(a[ptrA ++]);
    }
    while (ptrB < lengthB) {
        to.push_back(b[ptrB ++]);
    }
}
void buildTree(int I, int low, int high) {
    if (low == high) {
        stree[I] = vector<int>(1, data[low]);
        return;
    }
    int middle = (low + high) >> 1;
    buildTree(I << 1, low, middle);
    buildTree(I << 1 | 1, middle + 1, high);
    merge(stree[I << 1], stree[I << 1 | 1], stree[I]);
}
int get(int I, int low, int high, int l, int r, int height) {
    if (low > r || high < l) {
        return 0;
    }
    if (low >= l && high <= r) {
        vector<int>::iterator it = --lower_bound(stree[I].begin(), stree[I].end(), height + 1);
        if (*it > height) {
            return 0;
        }
        return *it;
    }
    int middle = (low + high) >> 1;
    return max(get(I << 1, low, middle, l, r, height),
               get(I << 1 | 1, middle + 1, high, l, r, height));
}

int main() {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &data[i]);
    }
    buildTree(1, 1, N);
    while (Q --) {
        int l, r, height;
        scanf("%d%d%d", &l, &r, &height);
        l ++; r ++;
        printf("%d\n", get(1, 1, N, l, r, height));
    }
    
    return 0;
}
