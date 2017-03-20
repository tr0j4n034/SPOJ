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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;
const int oo = 1 << 30;

typedef pair<int, int> pii;

int n, deleted;
long long timer, turns;
int a[me], ft[me];
long long ans[me];
pii st[me << 2];

void add(int pos, int value){
    pos += 2;
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    pos += 2;
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
pii merge(pii a, pii b){
    if(a.first < b.first || (a.first == b.first && a.second < b.second))
        return a;
    return b;
}
void build(int I, int low, int high){
    if(low == high){
        st[I] = make_pair(a[low], low);
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    st[I] = merge(st[I + I], st[I + I + 1]);
}
void update(int I, int low, int high, int pos, int value){
    if(low == high){
        st[I].first += value;
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(I + I, low, mid, pos, value);
    else update(I + I + 1, mid + 1, high, pos, value);
    st[I] = merge(st[I + I], st[I + I + 1]);
}
pii get(int I, int low, int high, int l, int r){
    if(low > r || high < l)
        return make_pair(oo, -1);
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return merge(get(I + I, low, mid, l, r),
                 get(I + I + 1, mid + 1, high, l, r));
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while(deleted < n){
        pii smallest = get(1, 1, n, 1, n);
        int value = smallest.first, current_pass = 0;
        timer += 1LL * (n - deleted) * (value - turns - 1);
        for( ; smallest.first == value; ){
            ans[smallest.second] = timer + smallest.second - get(smallest.second - 1) + current_pass;
            current_pass ++;
            add(smallest.second, 1);
            update(1, 1, n, smallest.second, oo);
            smallest = get(1, 1, n, 1, n);
        }
        timer += n - deleted;
        turns = value;
        deleted += current_pass;
    }
    for(int i = 1; i <= n; i ++)
        printf("%lld\n", ans[i]);
    
    return 0;
}