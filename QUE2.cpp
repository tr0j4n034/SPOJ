#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
 
using namespace std;
 
const int me = 100025;
 
typedef struct node{
    int value;
    int priority;
    int _cnt;
    node *l, *r;
}node;
typedef node* pnode;
 
int get_size(pnode t){
    return t? t->_cnt : 0;
}
void update_size(pnode t){
    if(t)
        t->_cnt = get_size(t->l) + 1 + get_size(t->r);
}
void Split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
    if(!t)
        return void(l = r = NULL);
    int cur_pos = get_size(t->l) + add;
    if(cur_pos + 1 <= pos)
        Split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else Split(t->l, l, t->l, pos, add), r = t;
    update_size(t);
}
void Merge(pnode &t, pnode l, pnode r){
    if(!l || !r)
        t = l? l : r;
    else if(l->priority > r->priority)
        Merge(l->r, l->r, r), t = l;
    else Merge(r->l, l, r->l), t = r;
    update_size(t);
}
pnode Init(int key){
    pnode p = (pnode)malloc(sizeof(node));
    p->value = key;
    p->priority = rand();
    p->_cnt = 1;
    p->l = p->r = NULL;
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
bool Find(pnode t, int key){
    if(!t)
        return false;
    if(t->value == key)
        return true;
    if(t->value > key)
        return Find(t->l, key);
    return Find(t->r, key);
}
int Kth_element(pnode t, int k){
    if(get_size(t->l) + 1 == k)
        return t->value;
    if(get_size(t->l) + 1 > k)
        return Kth_element(t->l, k);
    return Kth_element(t->r, k - get_size(t->l) - 1);
}
void Print(pnode t){
    if(!t)
        return;
    Print(t->l);
    cout << t->value << endl;
    Print(t->r);
}
 
 
int q, n;
pair<int, int> a[me];
 
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    srand(21312);
    
    scanf("%d", &q);
    while(q --){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i].first);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i].second);
        sort(a, a + n);
        pnode t = NULL;
        for(int i = n - 1; i >= 0; i --)
            Insert(t, a[i].second + 1, a[i].first);
        for(int i = 0; i < n; i ++){
            printf("%d", Kth_element(t, i + 1));
            if(i < n - 1)
                putchar(' ');
        }
        putchar('\n');
    }
    
    return 0;
} 