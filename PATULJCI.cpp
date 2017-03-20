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

const int me = 300025;

typedef struct node{
    int value;
    node *l, *r;
} node;
typedef node* pnode;

int n, m, l, r, k;
int a[me], v[me];
vector<int> pos[me];
pnode roots[me];
pnode dummy = NULL;

pnode Init(int value){
    pnode p = (pnode)malloc(sizeof(node));
    p->value = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void Relax(pnode &root){
    if(root->l)
        root->value += root->l->value;
    if(root->r)
        root->value += root->r->value;
}
int get_value(pnode &root){
    return root? root->value : 0;
}
pnode add_node(pnode &cur, int low, int high, int pos, int value){
    if(low > high)
        return dummy;
    if(!cur)
        cur = Init(0);
    if(low == pos && high == pos){
        return Init(cur->value + value);
    }
    int mid = (low + high) >> 1;
    pnode p = Init(0);
    if(pos <= mid){
        p->l = add_node(cur->l, low, mid, pos, value);
        p->r = cur->r;
    }
    else{
        p->l = cur->l;
        p->r = add_node(cur->r, mid + 1, high, pos, value);
    }
    Relax(p);
    return p;
}
int get(pnode &root, int low, int high, int l, int r){
    if(low > high || low > r || high < l)
        return 0;
    if(!root)
        root = Init(0);
    if(low >= l && high <= r)
        return root->value;
    int mid = (low + high) >> 1;
    return get(root->l, low, mid, l, r)
    + get(root->r, mid + 1, high, l, r);
}
int Kth_element(pnode &cur_left, pnode &cur_right, int low, int high, int k){
    if(!cur_left)
        cur_left = Init(0);
    if(!cur_right)
        cur_right = Init(0);
    if(low == high)
        return low;
    int mid = (low + high) >> 1;
    int sum = get_value(cur_right->l) - get_value(cur_left->l);
    if(sum >= k)
        return Kth_element(cur_left->l, cur_right->l, low, mid, k);
    else return Kth_element(cur_left->r, cur_right->r, mid + 1, high, k - sum);
}
void compress(){
    map<int, int> m, pos;
    for(int i = 1; i <= n; i ++)
        m[ a[i] ] = 1;
    int ptr = 1;
    for(auto i : m)
        pos[i.first] = ptr ++;
    for(int i = 1; i <= n; i ++){
        int value = a[i];
        a[i] = pos[ a[i] ];
        v[ a[i] ] = value;
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++)
        pos[a[i]].push_back(i);
    //compress();
    for(int i = 1; i <= n; i ++)
        roots[i] = add_node(roots[i - 1], 1, n, a[i], 1);
    scanf("%d", &m);
    for(int i = 0; i < m; i ++){
        scanf("%d%d", &l, &r);
        k = (r - l + 2) >> 1;
        int color = Kth_element(roots[l - 1], roots[r], 1, n, k);
        auto s = upper_bound(pos[color].begin(), pos[color].end(), r)
        - lower_bound(pos[color].begin(), pos[color].end(), l);
        if(s + s > r - l + 1)
            printf("yes %d\n", color);
        else printf("no\n");
    }
    
    
    return 0;
}