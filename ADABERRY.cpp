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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 200025;
const int MAX = 1000025;

struct node{
    int sum;
    node *l;
    node *r;
    node(){
        
    }
};
typedef node* pnode;

int N, Q;
int timer;
int a[me], in[me], out[me], result[me];
vector<int> edges[me];
pnode roots[me << 2];

void dfs(int node, int parent){
    ++timer;
    in[node] = timer;
    for(int i : edges[node]){
        if(i == parent)
            continue;
        dfs(i, node);
    }
    out[node] = timer;
}
int get(pnode &root){
    return root ? root->sum : 0;
}
pnode initialize(int value){
    pnode p = pnode(malloc(sizeof(node)));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void add(pnode &root, int low, int high, int pos, int value){
    if(!root)
        root = initialize(0);
    if(low == high){
        root->sum ++;
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        add(root->l, low, mid, pos, value);
    else add(root->r, mid + 1, high, pos, value);
    root->sum = get(root->l) + get(root->r);
}
int get(pnode &root, int low, int high, int l, int r){
    if(!root)
        return 0;
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return root->sum;
    int mid = (low + high) >> 1;
    return get(root->l, low, mid, l, r)
    + get(root->r, mid + 1, high, l, r);
}
void update(int I, int low, int high, int pos, int value){
    if(low == high){
        add(roots[I], 1, MAX, value, 1);
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(I << 1, low, mid, pos, value);
    else update(I << 1 | 1, mid + 1, high, pos, value);
    add(roots[I], 1, MAX, value, 1);
}
int get(int I, int low, int high, int l, int r, int value){
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return get(roots[I], 1, MAX, 1, value);
    int mid = (low + high) >> 1;
    return get(I << 1, low, mid, l, r, value)
    + get(I << 1 | 1, mid + 1, high, l, r, value);
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i < N; i ++){
        int u, v;
        scanf("%d%d", &u, &v);
        ++u, ++v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, -1);
    for(int i = 1; i <= N; i ++)
        update(1, 1, N << 1, in[i], a[i] + 1);
    for(int i = 0; i < Q; i ++){
        int root, number;
        scanf("%d%d", &root, &number);
        ++root;
        ++number;
        printf("%d\n", get(1, 1, N << 1, in[root], out[root], number - 1));
        update(1, 1, N << 1, in[root], number);
    }
    
    return 0;
}
