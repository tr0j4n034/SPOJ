//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/16/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100005;

struct node{
    int value;
    node *l;
    node *r;
    node () {
        
    }
};
typedef node* pnode;

int get (pnode &p) {
    return p ? p -> value : 0;
}
pnode initialize (int v) {
    pnode p = pnode(malloc(sizeof(node)));
    p -> value = v;
    p -> l = NULL;
    p -> r = NULL;
    return p;
}
pnode add (pnode &p, int low, int high, int position, int v) {
    if (!p) {
        p = initialize(0);
    }
    if (low == high) {
        pnode result = initialize(p -> value + v);
        return result;
    }
    int middle = (low + high) >> 1;
    pnode result = initialize(0);
    if (position <= middle) {
        result -> l = add(p -> l, low, middle, position, v);
        result -> r = p -> r;
    }
    else {
        result -> l = p -> l;
        result -> r = add(p -> r, middle + 1, high, position, v);
    }
    result -> value = get(result -> l) + get(result -> r);
    return result;
}
int getMiddle (pnode &L, pnode &R, int low, int high, int position) {
    if (!L) {
        L = initialize(0);
    }
    if (!R) {
        R = initialize(0);
    }
    if (low == high) {
        return low;
    }
    int skipped = get(R -> l) - get(L -> l);
    int middle = (low + high) >> 1;
    if (skipped >= position) {
        return getMiddle(L -> l, R -> l, low, middle, position);
    }
    else {
        return getMiddle(L -> r, R -> r, middle + 1, high, position - skipped);
    }
}

int N, Q;
int cases;
int data[MAX], realValue[MAX];
pnode roots[MAX];

int main(int argc, const char * argv[]) {
    while (scanf("%d", &N) != EOF) {
        cases ++;
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &data[i]);
        }
        vector<int> compressor = vector<int> (data + 1, data + N + 1);
        sort(compressor.begin(), compressor.end());
        compressor.erase(unique(compressor.begin(), compressor.end()), compressor.end());
        for (int i = 1; i <= N; i ++) {
            int v = data[i];
            data[i] = (int)(lower_bound(compressor.begin(), compressor.end(), data[i]) - compressor.begin()) + 1;
            realValue[data[i]] = v;
        }
        for (int i = 1; i <= N; i ++) {
            roots[i] = NULL;
            roots[i] = add(roots[i - 1], 1, MAX, data[i], 1);
        }
        scanf("%d", &Q);
        printf("Case %d:\n", cases);
        while (Q --) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", realValue[getMiddle(roots[l - 1], roots[r], 1, MAX, (r - l) / 2 + 1)]);
        }
    }
    
    return 0;
}
