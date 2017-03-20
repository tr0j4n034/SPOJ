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
node max(const node a, const node b){
    if(a < b)
        return a;
    return b;
}

int t, n;
node st[me << 2];
int a[me], ans[me], ft[me], lazy[me << 2];

void build(int I, int low, int high){
    if(low == high){
        st[I] = node(a[low], low);
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
    if(low > r || high < l)
        return node(123456789, -1);
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return min(get(I + I, low, mid, l, r), get(I + I, mid + 1, high, l, r));
}
void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
int get(int l, int r){
    return get(r) - get(l - 1);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
 
    scanf("%d", &t);
    for(int c = 0; c < t; c ++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        fill(lazy, lazy + (me << 2), 0);
        fill(st, st + (me << 2), node(123456789, -1));
        build(1, 1, n);
        for(int i = 1; i <= n; i ++){
            node g = get(1, 1, n, 1, n);
            ans[g.pos] = n - i + 1;
            update(1, 1, n, g.pos + 1, n, 1);
            update(1, 1, n, g.pos, g.pos, -n);
        }
        fill(ft, ft + me, 0);
        int ok = 1;
        for(int i = 1; i <= n && ok; i ++){
            if(get(ans[i] + 1, n) != a[i])
                ok = 0;
            else add(ans[i], 1);
        }
        printf("Test : %d\n", c + 1);
        if(!ok)
            puts("-1");
        else{
            for(int i = 1; i <= n; i ++){
                printf("%d", ans[i]);
                if(i < n)
                    putchar(' ');
            }
            putchar('\n');
        }
    }
    
    return 0;
}