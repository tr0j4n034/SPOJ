//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <utility>

using namespace std;

const int S = 10005;
const int MAX_VALUE = 1 << 28;
const int BLOCK_SIZE = 105;

struct query{
    int l;
    int r;
    int id;
    query() {
        
    }
    query(int l, int r, int id):
    l(l), r(r), id(id) {
        
    }
};

int N, M;
int a[S];
long long prefixSum[S];
query queries[S];
int means[S], medians[S], modes[S];

struct node{
    int sum;
    node *l;
    node *r;
    node () {
        
    }
};
typedef node* pnode;

int getValue(pnode &p) {
    return p ? p->sum : 0;
}
pnode initialize(int value) {
    pnode p = (pnode)malloc(sizeof(node));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void addInner(pnode &p, int low, int high, int position) {
    if (!p) p = initialize(0);
    if (low == high) {
        p->sum += +1;
        return;
    }
    int middle = (low + high) >> 1;
    if (position <= middle) addInner(p->l, low, middle, position);
    else addInner(p->r, middle + 1, high, position);
    p->sum = getValue(p->l) + getValue(p->r);
}
int getInner(pnode &p, int low, int high, int l, int r) {
    if (!p) return 0;
    if (low > r || high < l) return 0;
    if (low >= l && high <= r) return p->sum;
    int middle = (low + high) >> 1;
    return getInner(p->l, low, middle, l, r)
    + getInner(p->r, middle + 1, high, l, r);
}

pnode roots[S << 2];

void addOuter(int I, int low, int high, int position, int innerPosition) {
    addInner(roots[I], 1, MAX_VALUE, innerPosition);
    if (low == high) {
        return;
    }
    int middle = (low + high) >> 1;
    if (position <= middle) {
        addOuter(I << 1, low, middle, position, innerPosition);
    }
    else {
        addOuter(I << 1 | 1, middle + 1, high, position, innerPosition);
    }
}
int getOuter(int I, int low, int high, int outerL, int outerR, int innerL, int innerR) {
    if (low > outerR || high < outerL) return 0;
    if (low >= outerL && high <= outerR) return getInner(roots[I], 1, MAX_VALUE, innerL, innerR);
    int middle = (low + high) >> 1;
    return getOuter(I << 1, low, middle, outerL, outerR, innerL, innerR)
    + getOuter(I << 1 | 1, middle + 1, high, outerL, outerR, innerL, innerR);
}
int getKthElement(int l, int r, int k) {
    int low = 0, high = MAX_VALUE, middle, best = low;
    while (low <= high) {
        middle = (low + high + 1) >> 1;
        int counts = getOuter(1, 1, N, l, r, 1, middle);
        if (counts >= k) {
            best = middle;
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    return best;
}

void getMeans(query Q[S]) {
    for (int i = 1; i <= M; i ++) {
        long long sum = prefixSum[Q[i].r] - prefixSum[Q[i].l - 1];
        means[i] = (int)(sum / (Q[i].r - Q[i].l + 1));
    }
}
void getMedians(query Q[S]) {
    for (int i = 1; i <= M; i ++) {
        int size = Q[i].r - Q[i].l + 1;
        if (size & 1) {
            medians[i] = getKthElement(Q[i].l, Q[i].r, (size >> 1) + 1);
        }
        else {
            medians[i] = (getKthElement(Q[i].l, Q[i].r, (size >> 1))
                          + getKthElement(Q[i].l, Q[i].r, (size >> 1) + 1)) / 2;
        }
    }
}

map<int, int> counts;
set<pair<int, int>> occurrences;

void Add(int position) {
    int value = a[position];
    if (counts[value] > 0) {
        occurrences.erase(make_pair(counts[value], value));
    }
    counts[value] ++;
    occurrences.insert(make_pair(counts[value], value));
    
}
void Remove(int position) {
    int value = a[position];
    occurrences.erase(make_pair(counts[value], value));
    counts[value] --;
    if (counts[value] > 0) {
        occurrences.insert(make_pair(counts[value], value));
    }
    
}
void getModes(query Q[S]) {
    sort(Q + 1, Q + M + 1, [](query a, query b) {
        if (a.l / BLOCK_SIZE != b.l / BLOCK_SIZE) return a.l < b.l;
        else return a.r < b.r;
    });
    int L = 1, R = 0;
    for (int i = 1; i <= M; i ++) {
        while (L > queries[i].l) Add(--L);
        while (L < queries[i].l) Remove(L ++);
        while (R < queries[i].r) Add(++R);
        while (R > queries[i].r) Remove(R --);
        modes[queries[i].id] = (*--occurrences.end()).second;
    }
}

int main() {
    //cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        cin >> a[i];
    }
    cin >> M;
    for (int i = 1; i <= M; i ++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l ++;
        queries[i].r ++;
        queries[i].id = i;
    }
    for (int i = 1; i <= N; i ++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    for (int i = 1; i <= N; i ++) {
        addOuter(1, 1, N, i, a[i]);
    }
    getMeans(queries);
    getMedians(queries);
    getModes(queries);
    
    for (int i = 1; i <= M; i ++) {
        cout << means[i] << " " << medians[i] << " " << modes[i] << endl;
    }
    
    //cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
