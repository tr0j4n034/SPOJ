//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/28/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(Q * log(Q)) solution using decart trees
 Actually, it is my old code which I submitted a few months ago and got time limit exceeded verdict.
 Now, it gets accepted after a few tiny optimizations.
 Problem is the typical use of decart trees(treap) by which insertion, deletion, and other queries
  can be answered in O(log(N)) expected time.
 */

#include <bits/stdc++.h>

using namespace std;

const int me = 200025;

typedef struct node{
    int value;
    int subtree_value;
    int priority;
    int _cnt;
    node *l;
    node *r;
}node;

typedef node* pnode;

int get_size(pnode t){
    return t? t->_cnt : 0;
}
void update_size(pnode t){
    if(t)
        t->_cnt = get_size(t->l) + 1 + get_size(t->r);
}
int get_subtree_value(pnode t){
    return t? t->subtree_value : INT_MIN;
}
void update_node(pnode t){
    if(t){
        update_size(t);
        t->subtree_value = max(get_subtree_value(t->l), max(t->value, get_subtree_value(t->r)));
    }
}
void Split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
    if(!t)
        return void(l = r = NULL);
    int cur_pos = add + get_size(t->l);
    if(cur_pos <= pos)
        Split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else Split(t->l, l, t->l, pos, add), r = t;
    update_node(t);
}
void Merge(pnode &t, pnode l, pnode r){
    if(!l)
        t = r;
    else if(!r)
        t = l;
    else if(l->priority > r->priority)
        Merge(l->r, l->r, r), t = l;
    else Merge(r->l, l, r->l), t = r;
    update_node(t);
}
pnode Init(int key){
    pnode p = (pnode)malloc(sizeof(node));
    p->value = key;
    p->priority = rand();
    p->_cnt = 1;
    p->l = p->r = NULL;
    return p;
}
void Insert(pnode &t, pnode it, int pos){
    pnode l1, r1;
    Split(t, l1, r1, pos - 1);
    Merge(l1, l1, it);
    Merge(t, l1, r1);
    //update_node(t);
}
void Insert(pnode &t, int pos, int key){
    pnode p = Init(key);
    Insert(t, p, pos - 1);
}
void Erase(pnode &t, int pos){
    pnode l1, r1;
    Split(t, l1, r1, pos - 1);
    pnode l2, r2;
    Split(r1, l2, r2, 1);
    Merge(t, l1, r2);
    //update_node(t);
}
bool Find(pnode t, int key){
    if(!t)
        return false;
    else if(t->value == key)
        return true;
    else if(t->value < key)
        return Find(t->r, key);
    else return Find(t->l, key);
}
int Kth_element(pnode t, int pos){
    if(get_size(t->l) + 1 == pos)
        return t->value;
    else if(get_size(t->l) + 1 > pos)
        return Kth_element(t->l, pos);
    else return Kth_element(t->r, pos - get_size(t->l) - 1);
}
int query(pnode &t, int l, int r){
    pnode l1, r1;
    Split(t, l1, r1, l - 2);
    pnode l2, r2;
    Split(r1, l2, r2, r - l);
    int res = get_subtree_value(l2);
    Merge(r1, l2, r2);
    Merge(t, l1, r1);
    update_node(t);
    return res;
}
void Print(pnode t){
    if(!t)
        return;
    Print(t->l);
    cout << t->value << " " << t->priority << endl;
    Print(t->r);
}

int q;
int pos, x, y;
char type;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    srand(time(NULL));
    pnode t = NULL;
    
    scanf("%d", &q);
    
    for(int i = 0; i < q; i ++){
        scanf("\n%c", &type);
        if(type == 'A'){
            scanf("%d%d", &x, &pos);
            Insert(t, pos, x);
        }
        else{assert(type == 'Q');
            scanf("%d%d", &x, &y);
            printf("%d\n", query(t, x, y));
        }
    }
    
    return 0;
}
