//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/15/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O((N + Q) * log^2(N)) solution using 2D segment trees.
 Every node of outer (level 1) segment trees contain inner implicit segment tree.
 The inner nodes are implicit segment trees maintaining sum values for particular ranges.
 Coordinate compression technique has been used to eliminate extra container (map, ordered_set) usage...
 Fast input techniques has been used to boost I/O performance (actually, it doesn't make so much sense)...
 One of the best problems I have seen in SPOJ... <3
 Segment trees <3 <3
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAX = 150005;
int TREE_SIZE;

struct query{
    char type;
    int x;
    int y;
    query() {
        
    }
    query(char _type, int _x, int _y):
    type(_type), x(_x), y(_y) {
        
    }
    bool operator < (const query other) const{
        return y < other.y;
    }
};
struct tree{
    long long sum;
    tree* l;
    tree* r;
    tree() {
        
    }
};
typedef tree* ptree;

long long get(ptree &p) {
    return p ? p->sum : 0;
}
ptree initialize(long long value) {
    ptree p = (ptree)malloc(sizeof(tree));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void update(ptree &p, int low, int high, int position, int value) {
    if (!p) {
        p = initialize(0);
    }
    if (low == high) {
        p->sum += value;
        return;
    }
    int middle = (low + high) >> 1;
    if (position <= middle) {
        update(p->l, low, middle, position, value);
    }
    else {
        update(p->r, middle + 1, high, position, value);
    }
    p->sum = get(p->l) + get(p->r);
}
long long get(ptree &p, int low, int high, int l, int r) {
    if (!p) {
        return 0;
    }
    if (low > r || high < l) {
        return 0;
    }
    if (low >= l && high <= r) {
        return p->sum;
    }
    int middle = (low + high) >> 1;
    return get(p->l, low, middle, l, r)
    + get(p->r, middle + 1, high, l, r);
}

int N, M, Q;
int data[MAX], realValue[MAX];
query queries[MAX];
ptree segTree[MAX << 2];

set<int> occurrences[MAX];

//void build(int I, int low, int high);

void update(int I, int low, int high, int position, int treePosition, int value) {
    update(segTree[I], 1, TREE_SIZE, treePosition, value);
    if (low == high) {
        return;
    }
    int middle = (low + high) >> 1;
    if (position <= middle) {
        update(I << 1, low, middle, position, treePosition, value);
    }
    else {
        update(I << 1 | 1, middle + 1, high, position, treePosition, value);
    }
}
long long get(int I, int low, int high, int l, int r, int treeLow, int treeHigh) {
    if (low > r || high < l) {
        return 0;
    }
    if (low >= l && high <= r) {
        return get(segTree[I], 1, TREE_SIZE, treeLow, treeHigh);
    }
    int middle = (low + high) >> 1;
    return get(I << 1, low, middle, l, r, treeLow, treeHigh)
    + get(I << 1 | 1, middle + 1, high, l, r, treeLow, treeHigh);
}

template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int main() {
    //scanf("%d", &N);
    fastInput(N);
    for (int i = 1; i <= N; i ++) {
        //scanf("%d", &data[i]);
        fastInput(data[i]);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i ++) {
        scanf(" %c%d%d", &queries[i].type, &queries[i].x, &queries[i].y);
    }
    vector<int> values = vector<int>(data + 1, data + N + 1);
    for (int i = 0; i < Q; i ++) {
        if (queries[i].type == 'U') {
            values.push_back(queries[i].y);
        }
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 1; i <= N; i ++) {
        int oldValue = data[i];
        data[i] = (int)(lower_bound(values.begin(), values.end(), data[i]) - values.begin()) + 1;
        realValue[data[i]] = oldValue;
    }
    for (int i = 0; i < Q; i ++) {
        if (queries[i].type == 'U') {
            int oldValue = queries[i].y;
            queries[i].y = (int)(lower_bound(values.begin(), values.end(), queries[i].y) - values.begin()) + 1;
            realValue[queries[i].y] = oldValue;
        }
    }
    TREE_SIZE = N + 1; // define size for inner trees (ptree)
    for (int i = 1; i <= N; i ++) {
        if (data[i] < 1 || data[i] >= MAX) {
            continue;
        }
        occurrences[data[i]].insert(i);
    }
    for (int i = 1; i <= (int)values.size(); i ++) {
        occurrences[i].insert(0);
        occurrences[i].insert(TREE_SIZE);
    }
    for (int i = 1; i <= N; i ++) {
        auto nextIterator = occurrences[data[i]].upper_bound(i);
        update(1, 1, N, i, *nextIterator, realValue[data[i]]);
    }
    for (int i = 0; i < Q; i ++) {
        if (queries[i].type == 'Q') {
            printf("%lld\n", get(1, 1, N, queries[i].x, queries[i].y, queries[i].y + 1, TREE_SIZE));
        }
        else {
            if (data[queries[i].x] == queries[i].y) { // no update needed
                continue;
            }
            auto currentIterator = occurrences[data[queries[i].x]].lower_bound(queries[i].x);
            auto previousIterator = currentIterator; --previousIterator;
            auto nextIterator = currentIterator; ++nextIterator;
            // removing old element
            if (*previousIterator > 0) {
                update(1, 1, N, *previousIterator, queries[i].x, -realValue[data[*previousIterator]]);
                update(1, 1, N, *previousIterator, *nextIterator, +realValue[data[*previousIterator]]);
            }
            update(1, 1, N, queries[i].x, *nextIterator, -realValue[data[queries[i].x]]);
            occurrences[data[queries[i].x]].erase(currentIterator);
            
            // adding new element
            data[queries[i].x] = queries[i].y;
            occurrences[data[queries[i].x]].insert(queries[i].x);
            currentIterator = occurrences[data[queries[i].x]].lower_bound(queries[i].x);
            previousIterator = currentIterator; --previousIterator;
            nextIterator = currentIterator; ++nextIterator;
            if (*previousIterator > 0) {
                update(1, 1, N, *previousIterator, queries[i].x, +realValue[data[*previousIterator]]);
                update(1, 1, N, *previousIterator, *nextIterator, -realValue[data[*previousIterator]]);
            }
            update(1, 1, N, queries[i].x, *nextIterator, +realValue[data[queries[i].x]]);
        }
    }
    
    return 0;
}

