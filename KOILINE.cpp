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

const int me = 200025;
const int INF = 1 << 30;
struct node{
    int value;
    int pos;
    node() {}
    node(int value, int pos) : value(value), pos(pos) {}
    bool operator <(const node other)const{
        if(value != other.value)
            return value < other.value;
        return pos > other.pos;
    }
};
node min(node a, node b){
    if(a < b)
        return a;
    return b;
}

int n;
int h[me], s[me], ans[me], lazy[me << 2];
node st[me << 2];

void build(int I, int low, int high){
    if(low == high){
        st[I] = node(s[low], low);
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    st[I] = min(st[I + I], st[I + I + 1]);
}
void push(int I){
    if(lazy[I] != 0){
        st[I].value -= lazy[I];
        lazy[I + I] += lazy[I];
        lazy[I + I + 1] += lazy[I];
        lazy[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r, int value){
    push(I);
    if(low > r || high < l)
        return;
    if(low >= l && high <= r){
        lazy[I] += value;
        push(I);
        return;
    }
    int mid = (low + high) >> 1;
    update(I + I, low, mid, l, r, value);
    update(I + I + 1, mid + 1, high, l, r, value);
    st[I] = min(st[I + I], st[I + I + 1]);
}
node get(int I, int low, int high, int l, int r){
    push(I);
    if(low > l || high < r)
        return node(INF, -1);
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return min(get(I + I, low, mid, l, r),
               get(I + I + 1, mid + 1, high, l, r));
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &h[i]);
    sort(h + 1, h + n + 1);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &s[i]);
    build(1, 1, n);
    for(int i = 1; i <= n; i ++){
        node g = get(1, 1, n, 1, n);
        ans[g.pos] = h[i];
        update(1, 1, n, g.pos + 1, n, 1);
        update(1, 1, n, g.pos, g.pos, -n);
    }
    for(int i = 1; i <= n; i ++){
        printf("%d\n", ans[i]);
    }
    
    return 0;
}