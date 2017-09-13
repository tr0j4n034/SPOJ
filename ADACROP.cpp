//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 An O((N + Q) * log(N)) solution using implicit segment trees
 Data values are compressed to get rid of log(N) factor.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 200005;

int N, Q;
int data[MAX];
int position[MAX], value[MAX];

struct node {
    int sum;
    node *l;
    node *r;
    node () {
        
    }
};
typedef node * pnode;

int getValue (pnode p) {
    return p ? p->sum : 0;
}
pnode initialize (int value) {
    pnode p = pnode(malloc(sizeof(node)));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void updatePosition (pnode &root, int low, int high, int position, int value) {
    if (!root) {
        root = initialize(0);
    }
    if (low == high) {
        root->sum += value;
        return;
    }
    int middle = (low + high) >> 1;
    if (position <= middle) {
        updatePosition(root->l, low, middle, position, value);
    }
    else {
        updatePosition(root->r, middle + 1, high, position, value);
    }
    root->sum = getValue(root->l) + getValue(root->r);
}
int getInRange (pnode &root, int low, int high, int l, int r) {
    if (!root) {
        return 0;
    }
    if (low > r || high < l) {
        return 0;
    }
    if (low >= l && high <= r) {
        return root->sum;
    }
    int middle = (low + high) >> 1;
    return getInRange(root->l, low, middle, l, r)
    + getInRange(root->r, middle + 1, high, l, r);
}

pnode pool[MAX << 1];

int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i ++) {
        scanf("%d", &data[i]);
    }
    for (int i = 0; i < Q; i ++) {
        scanf("%d%d", &position[i], &value[i]);
    }
    vector<int> items = vector<int> (data, data + N);
    items.insert(items.end(), value, value + Q);
    sort(items.begin(), items.end());
    items.erase(unique(items.begin(), items.end()), items.end());
    
    for (int i = 0; i < N; i ++) {
        data[i] = (int)(lower_bound(items.begin(), items.end(), data[i]) - items.begin());
    }
    for (int i = 0; i < Q; i ++) {
        value[i] = (int)(lower_bound(items.begin(), items.end(), value[i]) - items.begin());
    }
    for (int i = 0; i < N; i ++) {
        updatePosition(pool[data[i]], 1, N, i + 1, 1);
    }
    for (int i = 0; i < Q; i ++) {
        printf("%d\n", getInRange(pool[value[i]], 1, N, 1, position[i]));
        if (data[position[i]] != value[i]) {
            updatePosition(pool[data[position[i]]], 1, N, position[i] + 1, -1);
            data[position[i]] = value[i];
            updatePosition(pool[data[position[i]]], 1, N, position[i] + 1, 1);
        }
    }
    
    return 0;
}
