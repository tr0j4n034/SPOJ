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
#include <stack>
#include <set>
#include <map>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 2500025;

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}
template<class T> static void uput(T n)
{
    char s[30];
    int x = 0;
    do { s[x ++]=(n % 10) + '0'; n /= 10; } while(n);
    for(int i = x - 1; i >= 0; i --) putchar(s[i]);
    putchar('\n');
}

typedef struct node{
    int value;
    int priority;
    int subtree_value;
    int _cnt;
    bool rev;
    node *l, *r;
}node;
typedef node* pnode;

int get_value(pnode t){
    return t? t->subtree_value : 1 << 30;
}
int get_size(pnode t){
    return t? t->_cnt : 0;
}
void update_value(pnode t){
    if(t)
        t->subtree_value = min(get_value(t->l),
                               min(t->value, get_value(t->r)));
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
        if(t->l)
            t->l->rev ^= 1;
        if(t->r)
            t->r->rev ^= 1;
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

pnode t = NULL;
int n, m, l, r;
int done = 0;

void Print(pnode t){
    if(!t)
        return;
    push(t);
    Print(t->l);
    printf("%d", t->value);
    done ++;
    if(done < n)
        putchar(' ');
    Print(t->r);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = uget();
    t = NULL;
    for(int i = 1; i <= n; i ++)
        Insert(t, i, i);
    m = uget();
    while(m --){
        l = uget(), r = uget();
        Reverse(t, l, r);
    }
    Print(t);
    putchar('\n');
    
    return 0;
}