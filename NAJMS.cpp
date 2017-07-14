//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 14/07/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

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
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 100025;

int T, N, Q;
int a[me];
long long st[me << 2], lazy[me << 2];

void build(int I, int low, int high){
    if(low == high){
        st[I] = a[low];
        return;
    }
    int middle = (low + high) >> 1;
    build(I << 1, low, middle);
    build(I << 1 | 1, middle + 1, high);
}
void push(int I, int low, int high){
    if(lazy[I]){
        st[I] += 1LL * lazy[I] * (high - low + 1);
        if(low != high){
            lazy[I << 1] += lazy[I];
            lazy[I << 1 | 1] += lazy[I];
        }
        lazy[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r, long long value){
    push(I, low, high);
    if(low > r || high < l){
        return;
    }
    if(low >= l && high <= r){
        lazy[I] += value;
        push(I, low, high);
        return;
    }
    int middle = (low + high) >> 1;
    update(I << 1, low, middle, l, r, value);
    update(I << 1 | 1, middle + 1, high, l, r, value);
    st[I] = st[I << 1] + st[I << 1 | 1];
}
long long get(int I, int low, int high, int l, int r){
    push(I, low, high);
    if(low > r || high < l){
        return 0;
    }
    if(low >= l && high <= r){
        return st[I];
    }
    int middle = (low + high) >> 1;
    return get(I << 1, low, middle, l, r)
    + get(I << 1 | 1, middle + 1, high, l, r);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    for(int c = 0; c < T; c ++){
        printf("Case %d:\n", c + 1);
        fill(lazy, lazy + (me << 1), 0);
        scanf("%d%d", &N, &Q);
        for(int i = 1; i <= N; i ++){
            scanf("%d", &a[i]);
        }
        build(1, 1, N);
        while(Q --){
            char type;
            scanf(" %c", &type);
            if(type == 'w'){
                int l, r, v;
                scanf("%d%d%d", &l, &r, &v);
                update(1, 1, N, l, r, v);
            }
            else if(type == 'm'){
                int x;
                scanf("%d", &x);
                long long v = get(1, 1, N, x, x);
                update(1, 1, N, x, x, -v);
            }
            else{
                int x;
                scanf("%d", &x);
                printf("%lld\n", get(1, 1, N, x, x));
            }
        }
    }
    
    return 0;
}
