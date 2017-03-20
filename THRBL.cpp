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
 
const int me = 100025;
 
int n, m;
int a[me], st[me << 2];
 
void build(int I, int low, int high){
    if(low == high){
        st[I] = a[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    st[I] = max(st[I + I], st[I + I + 1]);
}
int get(int I, int low, int high, int l, int r){
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return max(get(I + I, low, mid, l, r),
               get(I + I + 1, mid + 1, high, l, r));
}
 
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    int s = 0;
    while(m --){
        int x, y;
        scanf("%d%d", &x, &y);
        int g = get(1, 1, n, min(x, y), max(x, y) - 1);
        if(g == a[x])
            s ++;
    }
    printf("%d\n", s);
    
    return 0;
} 