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
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 100025;

typedef struct node{
    int value;
    int priority;
    int subtree_value;
    int _cnt;
    node *l, *r;
}node;
typedef node* pnode;

int get_value(pnode t){
    return t? t->subtree_value : 0;
}
int get_size(pnode t){
    return t? t->_cnt : 0;
}
void update_value(pnode t){
    if(t)
        t->subtree_value = get_value(t->l) + t->value + get_value(t->r);
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
void Swap(pnode &t, pnode &u, int l, int r){
    pnode l1, r1;
    Split(t, l1, r1, l - 1);
    pnode l2, r2;
    Split(r1, l2, r2, r - l + 1);
    
    pnode g1, h1;
    Split(u, g1, h1, l - 1);
    pnode g2, h2;
    Split(h1, g2, h2, r - l + 1);
    swap(l2, g2);
    
    Merge(r1, l2, r2);
    Merge(t, l1, r1);
    
    Merge(h1, g2, h2);
    Merge(u, g1, h1);
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
int Get_index(pnode &t, int key, int add = 0){
    if(t->value == key && get_value(t->l) > key)
        return get_size(t->l) + add + 1;
    else if(get_value(t->l) <= key)
        return Get_index(t->l, key, add);
    return Get_index(t->r, key, add + get_size(t->l) + 1);
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
inline int inp()
{
    int n = 0;
    int ch = getchar();int sign = 1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign = -1; ch=getchar();}
    
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
    return n*sign;
}
template<class T> static void uput(T n)
{
    char s[30];
    int x = 0;
    do { s[x ++]=(n % 10) + '0'; n /= 10; } while(n);
    for(int i = x - 1; i >= 0; i --) putchar(s[i]);
    putchar('\n');
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    pnode u = NULL, v = NULL;
    int type, pos, l, r, x;
    int n = inp(), m = inp();
    for(int i = 1; i <= n; i ++){
        Insert(u, i, 0);
        Insert(v, i, 0);
    }
    while(m --){
        type = inp();
        if(type == 0){
            pos = inp(), l = inp() + 1, r = inp() + 1;
            if(!pos)
                printf("%d\n",Query(u, l, r));
            else printf("%d\n", Query(v, l, r));
        }
        else if(type == 1){
            pos = inp(), l = inp() + 1, x = inp();
            if(!pos){
                Erase(u, l);
                Insert(u, l, x);
            }
            else{
                Erase(v, l);
                Insert(v, l, x);
            }
        }
        else{
            l = inp() + 1, r = inp() + 1;
            Swap(u, v, l, r);
        }
    }
    return 0;
}
