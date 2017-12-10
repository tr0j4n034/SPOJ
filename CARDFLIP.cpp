//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/10/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O((N + Q) * log(N)) solution using Decart trees
 The queries of type 1 and 2 are be handled in standard Decart tree implementations.
 And in order to work with queries of type 3,
 we can use the following approach:
 --> Keep a parent link from each tree node.
 --> Since we use pointers for each nodes, we can track any element using its pointer node... (<3)
 --> If we are required to reverse any range, parent links will not be affected.
 --> Update links when you do Merge/Split operations.
 --> When type-3 query come, first do update update operations until you reach root node.
 --> Finally, traverse the path to root and count sizes of skipped left subtrees till the root node.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cassert>

using namespace std;

const int MAX = 100005;
const int _INFINITY = 1 << 30;

struct node{
    int value;
    int priority;
    int subtree_value;
    int subtreeSize;
    bool reversed;
    node* leftChild;
    node* rightChild;
    node* parent;
    int state; // 0 --> left child, 1 --> right child
};

typedef node* tree;

int getValue(tree t){
    return t? t->subtree_value : _INFINITY;
}
int getSize(tree t){
    return t? t->subtreeSize : 0;
}
void update(tree t){
    if(t) {
        t->subtree_value = min(getValue(t->leftChild),
                               min(t->value, getValue(t->rightChild)));
        t->subtreeSize = getSize(t->leftChild) + 1 + getSize(t->rightChild);
        if (t->leftChild) {
            t->leftChild->parent = t;
            t->leftChild->state = 0;
        }
        if (t->rightChild) {
            t->rightChild->parent = t;
            t->rightChild->state = 1;
        }
    }
}

void push(tree t){
    if(t && t->reversed){
        update(t);
        t->reversed = 0;
        swap(t->leftChild, t->rightChild);
        if(t->leftChild) {
            t->leftChild->reversed ^= 1;
            t->leftChild->state ^= 1;
        }
        if(t->rightChild) {
            t->rightChild->reversed ^= 1;
            t->rightChild->state ^= 1;
        }
    }
}
void Split(tree t, tree &l, tree &r, int pos, int add = 0){
    if(!t)
        return void(l = r = NULL);
    push(t);
    int cur_pos = getSize(t->leftChild) + add;
    if(cur_pos + 1 <= pos) {
        Split(t->rightChild, t->rightChild, r, pos, cur_pos + 1);
        l = t;
    }
    else {
        Split(t->leftChild, l, t->leftChild, pos, add);
        r = t;
    }
    update(t);
}
void Merge(tree &t, tree l, tree r){
    push(l);
    push(r);
    if(!l || !r)
        t = l? l : r;
    else if(l->priority > r->priority) {
        Merge(l->rightChild, l->rightChild, r);
        t = l;
    }
    else {
        Merge(r->leftChild, l, r->leftChild);
        t = r;
    }
    update(t);
}
tree Initialize(int key){
    tree p = (tree)malloc(sizeof(node));
    p->value = key;
    p->priority = rand();
    p->subtree_value = key;
    p->subtreeSize = 1;
    p->reversed = 0;
    p->leftChild = NULL;
    p->rightChild = NULL;
    p->parent = NULL;
    p->state = 0;
    return p;
}
void Insert(tree &t, tree item, int position){
    tree l1, r1;
    Split(t, l1, r1, position - 1);
    Merge(l1, l1, item);
    Merge(t, l1, r1);
}
void Insert(tree &t, int position, int key){
    tree p = Initialize(key);
    Insert(t, p, position);
}
void Erase(tree &t, int position){
    tree l1, r1;
    Split(t, l1, r1, position - 1);
    tree l2, r2;
    Split(r1, l2, r2, 1);
    Merge(t, l1, r2);
}
void Reverse(tree &t, int l, int r){
    tree l1, r1;
    Split(t, l1, r1, l - 1);
    tree l2, r2;
    Split(r1, l2, r2, r - l + 1);
    l2->reversed ^= 1;
    Merge(r1, l2, r2);
    Merge(t, l1, r1);
}
int Query(tree &t, int l, int r){
    tree l1, r1;
    Split(t, l1, r1, l - 1);
    tree l2, r2;
    Split(r1, l2, r2, r - l + 1);
    int ans = getValue(l2);
    Merge(r1, l2, r2);
    Merge(t, l1, r1);
    return ans;
}
bool Find(tree t, int key){
    push(t);
    if(!t)
        return false;
    if(t->value == key)
        return true;
    if(t->value > key)
        return Find(t->leftChild, key);
    return Find(t->rightChild, key);
}
int Get_index(tree &t, int key, int add = 0){
    push(t);
    if(t->value == key && getValue(t->leftChild) > key)
        return getSize(t->leftChild) + add + 1;
    else if(getValue(t->leftChild) <= key)
        return Get_index(t->leftChild, key, add);
    return Get_index(t->rightChild, key, add + getSize(t->leftChild) + 1);
}
int Kth_element(tree t, int k){
    push(t);
    if(getSize(t->leftChild) + 1 == k)
        return t->value;
    if(getSize(t->leftChild) + 1 > k)
        return Kth_element(t->leftChild, k);
    return Kth_element(t->rightChild, k - getSize(t->leftChild) - 1);
}
void fixPath(tree &t) {
    if (!t) return;
    fixPath(t->parent);
    push(t);
}
int calculatePosition(tree &t, int lastState) {
    int skipped = 0;
    if (lastState == 1) skipped = 1 + getSize(t->leftChild);
    if (t->parent == NULL) return skipped;
    else return skipped + calculatePosition(t->parent, t->state);
}
int positionOfElement(tree &t) {
    fixPath(t);
    return calculatePosition(t, +1);
}
void assignParents(tree &t) {
    if (!t) return;
    if (t->leftChild) {
        t->leftChild->parent = t;
        t->leftChild->state = 0;
    }
    if (t->rightChild) {
        t->rightChild->parent = t;
        t->rightChild->state = 1;
    }
    assignParents(t->leftChild);
    assignParents(t->rightChild);
}
void Print(tree t){
    if(!t)
        return;
    push(t);
    Print(t->leftChild);
    cout << t->value << " ";
    Print(t->rightChild);
}

int N, Q;
int type, x, l, r;
tree t = NULL;
tree nodes[MAX];

int main() {
    srand(unsigned(time(NULL)));
    
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i ++){
        nodes[i] = Initialize(i);
        Insert(t, nodes[i], i);
    }
    assignParents(t);
    while (Q --){
        //Print(t); cout << endl;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d", &l, &r);
            Reverse(t, l, r);
        }
        else if(type == 2) {
            scanf("%d", &x);
            printf("%d\n", Kth_element(t, x));
        }
        else {
            scanf("%d", &x);
            printf("%d\n", positionOfElement(nodes[x]));
        }
    }
    
    return 0;
}
