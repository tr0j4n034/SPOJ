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

int n, m;
int a[me], depth[me], par[MAX_LOG][me];
pnode roots[me];
vector<int> v[me];

void dfs(int node, int p){
    par[0][node] = p;
    roots[node] = add(roots[p], 0, n, a[node], 1);
    for(int i : v[node]){
        if(i == p)
            continue;
        depth[i] = depth[node] + 1;
        dfs(i, node);
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
    
    int cases = 0;
    while(scanf("%d%d", &n, &m) != EOF){
        if(cases > 0)
            putchar('\n');
        cases ++;
        for(int i = 1; i <= n; i ++)
            a[i] = uget();
        for(int i = 1; i <= n; i ++)
            delete roots[i];
        for(int i = 1; i <= n; i ++)
            v[i].clear();
        for(int i = 1; i < n; i ++){
            int a = uget(), b = uget();
            v[a].push_back(b);
            v[b].push_back(a);
        }
        roots[0] = Init(0);
        for(int i = 0; i < MAX_LOG; i ++)
            for(int j = 1; j <= n; j ++)
                par[i][j] = 0;
        dfs(1, 0);
        for(int i = 1; i < MAX_LOG; i ++)
            for(int j = 1; j <= n; j ++)
                if(par[i - 1][j] != 0)
                    par[i][j] = par[i - 1][par[i - 1][j]];
        while(m --){
            int a = uget(), b = uget(), c = uget();
            int lca = LCA(a, b);
            int par_lca = lca == 1 ? 0 : par[0][lca];
            int s = get(roots[a], 0, n, c) + get(roots[b], 0, n, c)
            - get(roots[lca], 0, n, c) - get(roots[par_lca], 0, n, c);
            if(s > 0)
                puts("Find");
            else puts("NotFind");
        }
    }
    
    return 0;
}
