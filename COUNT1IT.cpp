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
const int sz = 1200000000;

struct node{
    int sum;
    node *l, *r;
    
    node() {}
};
typedef node * pnode;

int get(pnode &t){
    return t ? t->sum : 0;
}
pnode Init(int sum){
    pnode p = (pnode)malloc(sizeof(node));
    p->sum = sum;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void add(int low, int high, pnode &root, int pos, int value){
    if(!root)
        root = Init(0);
    if(low == high){
        root->sum += value;
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        add(low, mid, root->l, pos, value);
    else add(mid + 1, high, root->r, pos, value);
    root->sum = get(root->l) + get(root->r);
}
int get(int low, int high, pnode &root, int l, int r){
    if(low > r || high < l)
        return 0;
    if(!root)
        return 0;
    if(low >= l && high <= r)
        return root->sum;
    int mid = (low + high) >> 1;
    return get(low, mid, root->l, l, r)
    + get(mid + 1, high, root->r, l, r);
}
int Kth_element(int low, int high, pnode &root, int k){
    if(low == high)
        return low;
    int mid = (low + high) >> 1;
    int on_left = get(root->l);
    if(on_left >= k)
        return Kth_element(low, mid, root->l, k);
    else return Kth_element(mid + 1, high, root-> r, k - on_left);
}

int n, q, type, x;
pnode root;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    root = Init(0);
    
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &x);
        add(1, sz, root, x, 1);
    }
    while(q --){
        scanf("%d%d", &type, &x);
        if(type == 1){
            int cnt = get(1, sz, root, 1, x);
            add(1, sz, root, cnt + x, 1);
        }
        else if(type == 2){
            printf("%d\n", get(1, sz, root, 1, x));
        }
        else{
            if(get(root) < x)
                printf("invalid\n");
            else printf("%d\n", Kth_element(1, sz, root, x));
        }
    }
    
    return 0;
}