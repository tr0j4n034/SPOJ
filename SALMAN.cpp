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

const int me = 400025;

struct node{
    long long sum;
    long long lazy_add;
    long long smallest;
    node() {}
    node(long long sum, long long lazy, long long s)
        :sum(sum), lazy_add(lazy), smallest(s) {}
};

int T, N, Q;
int type, id;
int timer;
int has[me], in[me], out[me], w[me];
node st[me << 2];
vector<int> edges[me];

void dfs(int id){
    in[id] = ++timer;
    w[timer] = id;
    for(int i : edges[id]){
        dfs(i);
    }
    out[id] = timer;
}
void Merge(node &a, node b, node c){
    a.sum = b.sum + c.sum;
    a.smallest = min(b.smallest, c.smallest);
}
void Push(int I, int low, int high){
    if(st[I].lazy_add != 0){
        st[I].sum += 1LL * st[I].lazy_add * (high - low + 1);
        st[I].smallest += st[I].lazy_add;
        if(low != high){
            st[I << 1].lazy_add += st[I].lazy_add;
            st[I << 1 | 1].lazy_add += st[I].lazy_add;
        }
        st[I].lazy_add = 0;
    }
}
void Build(int I, int low, int high){
    if(low == high){
        st[I] = node(has[w[low]], 0, has[w[low]]);
        return;
    }
    int mid = (low + high) >> 1;
    Build(I << 1, low, mid);
    Build(I << 1 | 1, mid + 1, high);
    Merge(st[I], st[I << 1], st[I << 1 | 1]);
}
void UpdateRange(int I, int low, int high, int l, int r, int value){
    Push(I, low, high);
    if(low > r || high < l)
        return;
    if(low >= l && high <= r){
        st[I].lazy_add += value;
        Push(I, low, high);
        return;
    }
    int mid = (low + high) >> 1;
    UpdateRange(I << 1, low, mid, l, r, value);
    UpdateRange(I << 1 | 1, mid + 1, high, l, r, value);
    Merge(st[I], st[I << 1], st[I << 1 | 1]);
}
long long GetMin(int I, int low, int high, int l, int r){
    Push(I, low, high);
    if(low > r || high < l)
        return 1LL << 60;
    if(low >= l && high <= r)
        return st[I].smallest;
    int mid = (low + high) >> 1;
    return min(GetMin(I << 1, low, mid, l, r),
               GetMin(I << 1 | 1, mid + 1, high, l, r));
}
long long GetSum(int I, int low, int high, int l, int r){
    Push(I, low, high);
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I].sum;
    int mid = (low + high) >> 1;
    return GetSum(I << 1, low, mid, l, r)
    + GetSum(I << 1 | 1, mid + 1, high, l, r);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    //T = 1;
    for(int cases = 0; cases < T; cases ++){
        scanf("%d%d", &N, &Q);
        for(int i = 0; i < me; i ++)
            edges[i].clear();
        for(int i = 1; i <= N; i ++){
            int par;
            scanf("%d%d", &par, &has[i]);
            edges[par].push_back(i);
        }
        timer = 0;
        dfs(1);
        fill(st, st + (me << 2), node(0, 0, 0));
        Build(1, 1, N);
        printf("Case %d:\n", cases + 1);
        while(Q --){
            scanf("%d%d", &type, &id);
            if(type == 1){
                printf("%lld\n", GetSum(1, 1, N, in[id], out[id]));
            }
            else{
                int add = (int)min(GetMin(1, 1, N, in[id], out[id]), 1000LL);
                UpdateRange(1, 1, N, in[id], out[id], add);
            }
        }
    }
    
    return 0;
}
