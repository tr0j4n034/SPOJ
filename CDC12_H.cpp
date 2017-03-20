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

int t, n, m, l, r;
char type[20];
long long st[me << 2];
int lazy[me << 2];

void push(int I, int low, int high){
    if(lazy[I]){
        st[I] += 1LL * (high - low + 1) * lazy[I];
        lazy[I + I] += lazy[I];
        lazy[I + I + 1] += lazy[I];
        lazy[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r){
    push(I, low, high);
    if(low > high || low > r || high < l)
        return;
    if(low >= l && high <= r){
        lazy[I] ++;
        push(I, low, high);
        return;
    }
    int mid = (low + high) >> 1;
    update(I + I, low, mid, l, r);
    update(I + I + 1, mid + 1, high, l, r);
    st[I] = st[I + I] + st[I + I + 1];
}
long long get(int I, int low, int high, int l, int r){
    push(I, low, high);
    if(low > high || low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return get(I + I, low, mid, l, r)
    + get(I + I + 1, mid + 1, high, l, r);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    for(int c = 1; c <= t; c ++){
        printf("Scenario #%d:\n", c);
        scanf("%d%d", &n, &m);
        fill(st, st + (me << 2), 0);
        fill(lazy, lazy + (me << 2), 0);
        while(m --){
            scanf(" %s%d%d", type, &l, &r);
            if(type[0] == 'm'){
                update(1, 1, n, l, r);
                puts("OK");
            }
            else{
                printf("%lld\n", get(1, 1, n, l, r));
            }
        }
    }
    
    return 0;
}