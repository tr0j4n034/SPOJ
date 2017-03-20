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

const int me = 400025;
const int oo = 1 << 30;
typedef pair<int, int> pii;

int n, m, type, x, y;
int a[me], pos[me];
pii st[me << 2];

void merge(pii &a, pii b, pii c){
    a.first = min(b.first, c.first);
    a.second = max(b.second, c.second);
}
void build(int I, int low, int high){
    if(low == high){
        st[I] = make_pair(a[low], a[low]);
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    merge(st[I], st[I + I], st[I + I + 1]);
}
void update(int I, int low, int high, int pos, int value){
    if(low == high && low == pos){
        st[I] = make_pair(value, value);
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(I + I, low, mid, pos, value);
    else update(I + I + 1, mid + 1, high, pos, value);
    merge(st[I], st[I + I], st[I + I + 1]);
}
pii get(int I, int low, int high, int l, int r){
    if(low > r || high < l)
        return make_pair(oo, -oo);
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    pii g;
    merge(g, get(I + I, low, mid, l, r),
          get(I + I + 1, mid + 1, high, l, r));
    return g;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        a[i] = i;
        pos[i] = i;
    }
    build(1, 1, n);
    while(m --){
        scanf("%d%d%d", &type, &x, &y);
        if(type == 1){
            update(1, 1, n, pos[x], y);
            update(1, 1, n, pos[y], x);
            swap(pos[x], pos[y]);
        }
        else{
            int l = pos[x], r = pos[y];
            if(l > r)
                swap(l, r);
            pii g = get(1, 1, n, l, r);
            //printf("%d %d\n", g.first, g.second);
            if(r - l == y - x && g.first == x && g.second == y)
                printf("YES\n");
            else printf("NO\n");
        }
    }
    
    return 0;
}