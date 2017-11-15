//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/15/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * sqrt(Q) * log(N)) solution using SQRT decomposition
 Gets time limit exceeded verdict.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 150005;
const int MAGIC = 1102;

struct query{
    char type;
    int x;
    int y;
    int id;
    query() {
        
    }
    query(char _type, int _x, int _y, int _id):
    type(_type), x(_x), y(_y), id(_id) {
        
    }
    bool operator < (const query other) const{
        return y < other.y;
    }
};

int N, Q;
int data[MAX], realValue[MAX], lastOccurrence[MAX];
int importantCounts[MAX], importantData[MAX];
long long stree[MAX << 2], lazy[MAX << 2];
long long result[MAX];
query queries[MAX];
query askQueries[MAX], updateQueries[MAX]; // queries in blocks

//void build(int I, int low, int high);

void push(int I, int low, int high) {
    if (lazy[I] != 0) {
        stree[I] += lazy[I];
        if (low != high) {
            lazy[I << 1] += lazy[I];
            lazy[I << 1 | 1] += lazy[I];
        }
        lazy[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r, int value) {
    push(I, low, high);
    if (low > r || high < l) {
        return;
    }
    if (low >= l && high <= r) {
        lazy[I] += value;
        push(I, low, high);
        return;
    }
    int middle = (low + high) >> 1;
    update(I << 1, low, middle, l, r, value);
    update(I << 1 | 1, middle + 1, high, l, r, value);
}
long long get(int I, int low, int high, int position) {
    push(I, low, high);
    if (low == high) {
        return stree[I];
    }
    int middle = (low + high) >> 1;
    if (position <= middle) {
        return get(I << 1, low, middle, position);
    }
    else {
        return get(I << 1 | 1, middle + 1, high, position);
    }
}

struct node{
    int value;
    node *l;
    node *r;
    node () {
        
    }
};
typedef node* pnode;

int get(pnode &p) {
    return p ? p->value : 0;
}
pnode initialize(int value) {
    pnode p = pnode(malloc(sizeof(node)));
    p->value = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void update(pnode &root, int low, int high, int position, int value) {
    if (!root) {
        root = initialize(0);
    }
    if (low == high) {
        root->value += value;
        return;
    }
    int middle = (low + high) >> 1;
    if (position <= middle) {
        update(root->l, low, middle, position, value);
    }
    else {
        update(root->r, middle + 1, high, position, value);
    }
    root->value = get(root->l) + get(root->r);
}
int get(pnode &root, int low, int high, int l, int r) {
    if (!root) {
        return 0;
    }
    if (low > r || high < l) {
        return 0;
    }
    if (low >= l && high <= r) {
        return root->value;
    }
    int middle = (low + high) >> 1;
    return get(root->l, low, middle, l, r)
    + get(root->r, middle + 1, high, l, r);
}

pnode occurences[MAX];

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
        //scanf(" %c%d%d", &queries[i].type, &queries[i].x, &queries[i].y);
        scanf(" %c", &queries[i].type);
        fastInput(queries[i].x);
        fastInput(queries[i].y);
        queries[i].id = i;
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
    for (int i = 0; i < Q; i += MAGIC) {
        fill(stree, stree + (N << 2), 0);
        fill(lazy, lazy + (N << 2), 0);
        fill(lastOccurrence, lastOccurrence + MAX, 0);
        for (int j = 1; j < MAX; j ++) {
            occurences[j] = NULL;
        }
        int blockSize = min(Q, i + MAGIC) - i;
        int askSize = 0, updateSize = 0;
        for (int j = i; j < i + blockSize; j ++) {
            if (queries[j].type == 'Q') {
                askQueries[askSize ++] = queries[j];
            }
            else {
                updateQueries[updateSize ++] = queries[j];
            }
        }
        sort(askQueries, askQueries + askSize);
        int added = 0;
        for (int j = 0; j < askSize; j ++) {
            while (added < askQueries[j].y) {
                ++added;
                update(1, 1, N, lastOccurrence[data[added]] + 1, added, realValue[data[added]]);
                lastOccurrence[data[added]] = added;
                update(occurences[data[added]], 1, N, added, 1);
            }
            long long currentResult = get(1, 1, N, askQueries[j].x);
            for (int k = 0; k < updateSize && updateQueries[k].id < askQueries[j].id; k ++) {
                if (updateQueries[k].x > askQueries[j].y || updateQueries[k].x < askQueries[j].x) {
                    continue;
                }
                importantCounts[data[updateQueries[k].x]] = get(occurences[data[updateQueries[k].x]], 1, N, askQueries[j].x, askQueries[j].y);
                importantCounts[updateQueries[k].y] = get(occurences[updateQueries[k].y], 1, N,
                                                          askQueries[j].x, askQueries[j].y);
                importantData[updateQueries[k].x] = data[updateQueries[k].x];
            }
            for (int k = 0; k < updateSize && updateQueries[k].id < askQueries[j].id; k ++) {
                if (updateQueries[k].x > askQueries[j].y || updateQueries[k].x < askQueries[j].x) {
                    continue;
                }
                int oldValue = importantData[updateQueries[k].x];
                int newValue = updateQueries[k].y;
                importantCounts[oldValue] --;
                if (importantCounts[oldValue] == 0) {
                    currentResult -= realValue[oldValue];
                }
                importantData[updateQueries[k].x] = newValue;
                importantCounts[newValue] ++;
                if (importantCounts[newValue] == 1) {
                    currentResult += realValue[newValue];
                }
            }
            result[askQueries[j].id] = currentResult;
        }
        for (int j = 0; j < updateSize; j ++) {
            data[updateQueries[j].x] = updateQueries[j].y;
        }
    }
    for (int i = 0; i < Q; i ++) {
        if (queries[i].type == 'Q') {
            printf("%lld\n", result[i]);
        }
    }
    
    return 0;
}
/*
 5
 2 5 3 4 1
 6
 Q 2 5
 U 1 3
 Q 1 5
 U 4 2
 Q 2 4
 Q 2 3
 
 
 2 5 3 4 1
 query
 3 5 3 4 1
 query
 3 5 3 2 1
 query
 query
 
 
 5
 2 5 3 4 1
 3
 Q 2 5
 Q 1 5
 Q 2 4
 
 */
