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

const int me = 100025;
const int MAX_LOG = 20;

struct node{
    int sum;
    node *l, *r;
    node() {}
};
typedef node* pnode;

int n, q;
int cost[me], real[me], rc[me], par[MAX_LOG][me], depth[me];
vector<int> values;
vector<int> v[me];
pnode roots[me];

int get(pnode p){
    return p ? p->sum : 0;
}
pnode Init(int value){
    pnode p = (pnode)(malloc(sizeof(node)));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
pnode add(pnode &root, int low, int high, int pos, int value){
    if(!root)
        root = Init(0);
    if(low == high){
        return Init(value + get(root));
    }
    int mid = (low + high) >> 1;
    pnode p = Init(0);
    if(pos <= mid){
        p->l = add(root->l, low, mid, pos, value);
        p->r = root->r;
    }
    else{
        p->l = root->l;
        p->r = add(root->r, mid + 1, high, pos, value);
    }
    p->sum = get(p->l) + get(p->r);
    return p;
}
int get(pnode &root, int low, int high, int l, int r){
    if(low > r || high < l)
        return 0;
    if(!root)
        return 0;
    if(low >= l && high <= r)
        return root->sum;
    int mid = (low + high) >> 1;
    return get(root->l, low, mid, l, r)
    + get(root->r, mid + 1, high, l, r);
}
/// f(a, b) = get(a) + get(b) - get(lca(a, b)) - get(par(lca(a, b)));
int get(pnode &root_a, pnode &root_b, pnode &root_lca, pnode &root_par_lca, int low, int high, int k){
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
    int s = get(root_a->l) + get(root_b->l) - get(root_lca->l) - get(root_par_lca->l);
    int mid = (low + high) >> 1;
    if(s >= k)
        return get(root_a->l, root_b->l, root_lca->l, root_par_lca->l, low, mid, k);
    return get(root_a->r, root_b->r, root_lca->r, root_par_lca->r, mid + 1, high, k - s);
}

void dfs(int node, int p){
    par[0][node] = p;
    for(int ii = 0; ii < (int)v[node].size(); ii ++){
        int i = v[node][ii];
        if(i == p)
            continue;
        roots[i] = add(roots[node], 1, n, cost[i], 1);
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
    
    n = uget();
    q = uget();
    for(int i = 1; i <= n; i ++)
        real[i] = uget();
    values = vector<int>(real + 1, real + n + 1);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for(int i = 1; i <= n; i ++){
        cost[i] = (int)(lower_bound(values.begin(), values.end(), real[i]) - values.begin()) + 1;
        rc[cost[i]] = real[i];
    }
    for(int i = 1; i < n; i ++){
        int a = uget(), b = uget();
        v[a].push_back(b);
        v[b].push_back(a);
    }
    roots[0] = Init(0);
    roots[1] = add(roots[0], 1, n, cost[1], 1);
    dfs(1, -1);
    for(int i = 1; i < MAX_LOG; i ++)
        for(int j = 1; j <= n; j ++)
            if(par[i - 1][j] != -1)
                par[i][j] = par[i - 1][par[i - 1][j]];
    for(int i = 0; i < 0; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a < 1)
            break;
        cout << get(roots[a], 1, n, b, c) << endl;
    }
    while(q --){
        int a = uget(), b = uget(), k = uget();
        int lca = LCA(a, b);
        uput(rc[get(roots[a], roots[b], roots[lca], lca == 1 ? roots[0] : roots[par[0][lca]], 1, n, k)]);
    }
    
    return 0;
}
