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

int n, m, type, x, timer;
char c;
int in[me], out[me], st[me << 2][26];
char s[me];
vector<int> v[me];

void dfs(int node, int par){
    in[node] = ++timer;
    for(int i : v[node])
        if(i != par)
            dfs(i, node);
    out[node] = timer;
}
void build(int I, int low, int high){
    if(low == high){
        st[I][s[low]] = 1;
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    for(int i = 0; i < 26; i ++)
        st[I][i] = st[I + I][i] + st[I + I + 1][i];
}
void update(int I, int w, int low, int high, int pos, int value){
    if(low == high && low == pos){
        st[I][w] += value;
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(I + I, w, low, mid, pos, value);
    else update(I + I + 1, w, mid + 1, high, pos, value);
    st[I][w] = st[I + I][w] + st[I + I + 1][w];
}
int get(int I, int w, int low, int high, int l, int r){
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I][w];
    int mid = (low + high) >> 1;
    return get(I + I, w, low, mid, l, r)
    + get(I + I + 1, w, mid + 1, high, l, r);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i < n; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1);
    scanf(" %s", s);
    for(int i = n - 1; i >= 0; i --)
        s[i + 1] = s[i] - 'a';
    for(int i = 1; i <= n; i ++)
        update(1, s[i], 1, n, in[i], 1);
    //build(1, 1, n);
    scanf("%d", &m);
    while(m --){
        scanf("%d", &type);
        if(type == 0){
            scanf("%d %c", &x, &c);
            update(1, s[x], 1, n, in[x], -1);
            s[x] = c - 'a';
            update(1, s[x], 1, n, in[x], 1);
        }
        else{
            scanf("%d", &x);
            int odd = 0;
            for(int i = 0; i < 26 && odd < 2; i ++){
                if(get(1, i, 1, n, in[x], out[x]) & 1)
                    odd ++;
            }
            if(odd < 2)
                printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}