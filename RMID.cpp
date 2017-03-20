#include <bits/stdc++.h>
 
using namespace std;
 
const int me = 100025;
 
 
typedef struct node{
    int value;
    int priority;
    int subtree_value;
    int _cnt;
    node *l, *r;
} node;
typedef node* pnode;
 
int get_value(pnode t){
    return t? t->subtree_value : INT_MIN;
}
int get_size(pnode t){
    return t? t->_cnt : 0;
}
void update_value(pnode t){
    if(t)
        t->subtree_value = max(get_value(t->l),
                       max(t->value, get_value(t->r)));
}
void update_size(pnode t){
    if(t)
        t->_cnt = get_size(t->l) + 1 + get_size(t->r);
}
void Split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
    if(!t)
        return void(l = r = NULL);
    int cur_pos = add + get_size(t->l);
    if(cur_pos + 1 <= pos)
        Split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else
        Split(t->l, l, t->l, pos, add), r = t;
    update_size(t);
    update_value(t);
}
void Merge(pnode &t, pnode l, pnode r){
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
    p->l = NULL;
    p->r = NULL;
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
bool Find(pnode &t, int key){
    if(!t)
        return false;
    if(t->value == key)
        return true;
    if(t->value > key)
        return Find(t->l, key);
    return Find(t->r, key);
}
int Kth_element(pnode &t, int k){
    if(get_size(t->l) + 1 == k)
        return t->value;
    if(get_size(t->l) + 1 >= k)
        return Kth_element(t->l, k);
    else return Kth_element(t->r, k - get_size(t->l) - 1);
}
int Order_of_key_(pnode &t, int key, int add = 0){
    if(t->value == key)
        return add + get_size(t->l) + 1;
    if(t->value >= key)
        return Order_of_key_(t->l, key, add);
    return Order_of_key_(t->r, key, add + 1);
}
int Order_of_key(pnode &t, int key){
    if(!Find(t, key))
        return INT_MIN;
    return Order_of_key_(t, key);
}
int Find_pos(pnode &t, int key, int add = 0){
    if(!t || t->value == key)
        return add + 1;
    if(t->value > key)
        return Find_pos(t->l, key, add);
    else return Find_pos(t->r, key, add + get_size(t->l) + 1);
}
void Insert_in_order(pnode &t, int key){
    int pos = Find_pos(t, key);
    Insert(t, pos, key);
}
int Query(pnode &t, int l, int r){
    pnode l1, r1;
    Split(t, l1, r1, l - 1);
    pnode l2, r2;
    Split(r1, l2, r2, r - l + 1);
    int res = get_value(l2);
    Merge(r1, l2, r2);
    Merge(t, l1, r1);
    return res;
}
void Print(pnode &t){
    if(!t)
        return;
    Print(t->l);
    cout << t->value << endl;
    Print(t->r);
}
void Clear(pnode &t){
    if(!t)
        return;
    Clear(t->l);
    Clear(t->r);
    t = NULL;
}
 
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
 
    srand(time(NULL));
    pnode t = NULL;
    int p, x, f = 0;
 
    //scanf("%d", &p);
    Clear(t);
    while(scanf("%d", &x) != EOF){
        if(x == 0){
            Clear(t);
            if(f)
                printf("\n");
            f = 1;
        }
        else if(x > 0)
            Insert_in_order(t, x);
        else{
            int sz = get_size(t);
            int mid = (sz + 1) >> 1;
            printf("%d\n", Kth_element(t, mid));
            Erase(t, mid);
        }
    }
 
    return 0;
}