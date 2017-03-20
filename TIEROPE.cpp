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

const int me = 200025;
const int MAX_VALUE = 1000000;
const int MAX_LOG = 19;

struct node{
    int sum;
    node *l, *r;
    node() {}
};
typedef node* pnode;

int get(pnode &t){
    return t? t->sum : 0;
}
pnode Init(int value){
    pnode t = (pnode)(malloc(sizeof(node)));
    t->sum = value;
    t->l = NULL;
    t->r = NULL;
    return t;
}
pnode add(pnode &root, int low, int high, int pos, int value){
    if(!root)
        root = Init(0);
    if(low == high){
        pnode t = Init(root->sum + value);
        return t;
    }
    int mid = (low + high) >> 1;
    pnode t = (pnode)(malloc(sizeof(node)));
    if(pos <= mid){
        t->l = add(root->l, low, mid, pos, value);
        t->r = root->r;
    }
    else{
        t->l = root->l;
        t->r = add(root->r, mid + 1, high, pos, value);
    }
    t->sum = get(t->l) + get(t->r);
    return t;
}
int get(pnode &root, int low, int high, int pos){
    if(!root)
        return 0;
    if(low == high)
        return root->sum;
    int mid = (low + high) >> 1;
    if(pos <= mid)
        return get(root->l, low, mid, pos);
    else return get(root->r, mid + 1, high, pos);
}
int go1(pnode &root_a, pnode &root_b, pnode &root_lca, pnode &root_par_lca, int low, int high){
    if(low == high)
        return low;
    if(!root_a)
        root_a = Init(0);
    if(!root_b)
        root_b = Init(0);
    if(!root_lca)
        root_lca = Init(0);
    if(!root_par_lca)
        root_par_lca = Init(0);
    int mid = (low + high) >> 1;
    int s = get(root_a->r) + get(root_b->r) - get(root_lca->r) - get(root_par_lca->r);
    if(s > 0)
        return go1(root_a->r, root_b->r, root_lca->r, root_par_lca->r, mid + 1, high);
    else return go1(root_a->l, root_b->l, root_lca->l, root_par_lca->l, low, mid);
}
int go2(pnode &root_a, pnode &root_b, pnode &root_lca, pnode &root_par_lca, int low, int high){
    if(low == high)
        return low;
    if(!root_a)
        root_a = Init(0);
    if(!root_b)
        root_b = Init(0);
    if(!root_lca)
        root_lca = Init(0);
    if(!root_par_lca)
        root_par_lca = Init(0);
    int mid = (low + high) >> 1;
    int s = get(root_a->l) + get(root_b->l) - get(root_lca->l) - get(root_par_lca->l);
    if(s < 1)
        return go2(root_a->r, root_b->r, root_lca->r, root_par_lca->r, mid + 1, high);
    else return go2(root_a->l, root_b->l, root_lca->l, root_par_lca->l, low, mid);
}

int n, m;
int depth[me], par[MAX_LOG][me];
pnode roots[me];
vector<pair<int, int>> v[me];

void dfs(int node, int p){
    par[0][node] = p;
    for(auto i : v[node]){
        if(i.first == p)
            continue;
        roots[i.first] = add(roots[node], 1, MAX_VALUE, i.second, 1);
        depth[i.first] = depth[node] + 1;
        dfs(i.first, node);
    }
}
int LCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = par[i][a];
    if(a == b)
        return a;
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(par[i][a] != -1 && par[i][a] != par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    return par[0][a];
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = uget();
    for(int i = 1; i < n; i ++){
        int a = uget(), b = uget(), c = uget();
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    roots[0] = roots[1] = Init(0);
    dfs(1, 0);
    for(int i = 1; i < MAX_LOG; i ++)
        for(int j = 1; j <= n; j ++)
            if(par[i - 1][j] != 0)
                par[i][j] = par[i - 1][par[i - 1][j]];
    m = uget();
    while(m --){
        int a = uget(), b = uget();
        int lca = LCA(a, b);
        int par_lca = lca;
        printf("%d %d\n", go2(roots[a], roots[b], roots[lca], roots[par_lca], 1, MAX_VALUE),
               go1(roots[a], roots[b], roots[lca], roots[par_lca], 1, MAX_VALUE));
    }
    
    
    return 0;
}