//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/10/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 Original solution using Decart treee
 For a cleaner one, please refer to the next solution.
 */

#include <bits/stdc++.h>

using namespace std;

const int me = 100025;

typedef struct node{
    int value;
    int priority;
    int subtree_value;
    int _cnt;
    bool rev;
    node *l, *r;
    node* parent;
    int state; // 0 --> left child, 1 --> right child
}node;
typedef node* pnode;

int get_value(pnode t){
    return t? t->subtree_value : INT_MAX;
}
int get_size(pnode t){
    return t? t->_cnt : 0;
}
void update_value(pnode t){
    if(t)
        t->subtree_value = min(get_value(t->l),
                               min(t->value, get_value(t->r)));
    if (t) {
        if (t->l) {
            t->l->parent = t;
            t->l->state = 0;
        }
        if (t->r) {
            t->r->parent = t;
            t->r->state = 1;
        }
    }
}
void update_size(pnode t){
    if(t)
        t->_cnt = get_size(t->l) + 1 + get_size(t->r);
}
void push(pnode t){
    if(t && t->rev){
        update_size(t);
        update_value(t);
        t->rev = 0;
        swap(t->l, t->r);
        if(t->l) {
            t->l->rev ^= 1;
            t->l->state ^= 1;
        }
        if(t->r) {
            t->r->rev ^= 1;
            t->r->state ^= 1;
        }
    }
}
void Split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
    if(!t)
        return void(l = r = NULL);
    push(t);
    int cur_pos = get_size(t->l) + add;
    if(cur_pos + 1 <= pos)
        Split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else Split(t->l, l, t->l, pos, add), r = t;
    update_size(t);
    update_value(t);
}
void Merge(pnode &t, pnode l, pnode r){
    push(l);
    push(r);
    if(!l || !r)
        t = l? l : r;
    else if(l->priority > r->priority)
        Merge(l->r, l->r, r), t = l;
    else Merge(r->l, l, r->l), t = r;
    update_size(t);
    update_value(t);
}
pnode Init(int key){
    pnode p = (pnode)malloc(sizeof(node));
    p->value = key;
    p->priority = rand();
    p->subtree_value = key;
    p->_cnt = 1;
    p->rev = 0;
    p->l = p->r = NULL;
    p->parent = NULL;
    p->state = 0;
    return p;
}
void Insert(pnode &t, pnode item, int pos){
    pnode l1, r1;
    Split(t, l1, r1, pos - 1);
    Merge(l1, l1, item);
    Merge(t, l1, r1);
}
void Insert(pnode &t, int pos, int key){
    pnode p = Init(key);
    Insert(t, p, pos);
}
void Erase(pnode &t, int pos){
    pnode l1, r1;
    Split(t, l1, r1, pos - 1);
    pnode l2, r2;
    Split(r1, l2, r2, 1);
    Merge(t, l1, r2);
}
void Reverse(pnode &t, int l, int r){
    pnode l1, r1;
    Split(t, l1, r1, l - 1);
    pnode l2, r2;
    Split(r1, l2, r2, r - l + 1);
    l2->rev ^= 1;
    Merge(r1, l2, r2);
    Merge(t, l1, r1);
}
int Query(pnode &t, int l, int r){
    pnode l1, r1;
    Split(t, l1, r1, l - 1);
    pnode l2, r2;
    Split(r1, l2, r2, r - l + 1);
    int ans = get_value(l2);
    Merge(r1, l2, r2);
    Merge(t, l1, r1);
    return ans;
}
bool Find(pnode t, int key){
    push(t);
    if(!t)
        return false;
    if(t->value == key)
        return true;
    if(t->value > key)
        return Find(t->l, key);
    return Find(t->r, key);
}
int Get_index(pnode &t, int key, int add = 0){
    push(t);
    if(t->value == key && get_value(t->l) > key)
        return get_size(t->l) + add + 1;
    else if(get_value(t->l) <= key)
        return Get_index(t->l, key, add);
    return Get_index(t->r, key, add + get_size(t->l) + 1);
}
int Kth_element(pnode t, int k){
    push(t);
    if(get_size(t->l) + 1 == k)
        return t->value;
    if(get_size(t->l) + 1 > k)
        return Kth_element(t->l, k);
    return Kth_element(t->r, k - get_size(t->l) - 1);
}
void fixPath(pnode &t) {
    if (!t) return;
    fixPath(t->parent);
    push(t);
}
int calculatePosition(pnode &t, int lastState) {
    int skipped = 0;
    if (lastState == 1) skipped = 1 + get_size(t->l);
    if (t->parent == NULL) return skipped;
    else return skipped + calculatePosition(t->parent, t->state);
}
int positionOfElement(pnode &t) {
    fixPath(t);
    return calculatePosition(t, +1);
}
void assignParents(pnode &t) {
    if (!t) return;
    if (t->l) {
        t->l->parent = t;
        t->l->state = 0;
    }
    if (t->r) {
        t->r->parent = t;
        t->r->state = 1;
    }
    assignParents(t->l);
    assignParents(t->r);
}
void Print(pnode t){
    if(!t)
        return;
    push(t);
    Print(t->l);
    cout << t->value << " ";
    Print(t->r);
}

const int MAX = 100005;
pnode nodes[MAX];
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    pnode t = NULL;
    int n, q, x, type, l, r;
    
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++){
        //scanf("%d", &x);
        nodes[i] = Init(i);
        Insert(t, nodes[i], i);
    }
    assignParents(t);
    while (q --){
        //Print(t); cout << endl;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d", &l, &r);
            Reverse(t, l, r);
            //bruteReverse(l, r);
        }
        else if(type == 2) {
            scanf("%d", &x);// cout << "in type 2 query " << endl;
            //assert(KthElement(t, x) == bruteGetElement(x));
            printf("%d\n", Kth_element(t, x));
        }
        else {
            scanf("%d", &x); //cout << "here" << endl;
            //assert(positionOfElement(nodes[x]) == bruteGetPosition(x));
            printf("%d\n", positionOfElement(nodes[x]));
        }
    }
    putchar('\n');
    
    return 0;
}
