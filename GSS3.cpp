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

using namespace std;

const int me = 100025;
const long long oo = 1LL << 45;

struct node{
    long long sum;
    long long max_sum;
    long long prefix;
    long long suffix;
    node() {}
    node(long long sum, long long max_sum, long long prefix, long long suffix)
        : sum(sum), max_sum(max_sum), prefix(prefix), suffix(suffix) {}
};

int n, q, type, l, r, x;
int a[me];
node st[me << 2];

void merge(node &a, node b, node c){
    a.sum = b.sum + c.sum;
    a.prefix = max(b.prefix, b.sum + c.prefix);
    a.suffix = max(c.suffix, c.sum + b.suffix);
    a.max_sum = max(b.max_sum, c.max_sum);
    a.max_sum = max(a.max_sum, b.suffix + c.prefix);
}
void build(int I, int low, int high){
    if(low == high){
        st[I] = node(a[low], a[low], a[low], a[low]);
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    merge(st[I], st[I + I], st[I + I + 1]);
}
void update(int I, int low, int high, int pos, int value){
    if(low == high){
        a[low] = value;
        st[I] = node(a[low], a[low], a[low], a[low]);
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(I + I, low, mid, pos, value);
    else update(I + I + 1, mid + 1, high, pos, value);
    merge(st[I], st[I + I], st[I + I + 1]);
}
node get(int I, int low, int high, int l, int r){
    if(low > r || high < l)
        return node(-oo, -oo, -oo, -oo);
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    node p;
    merge(p, get(I + I, low, mid, l, r), get(I + I + 1, mid + 1, high, l, r));
    return p;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &q);
    while(q --){
        scanf("%d", &type);
        if(type == 0){
            scanf("%d%d", &l, &x);
            update(1, 1, n, l, x);
        }
        else{
            scanf("%d%d", &l, &r);
            printf("%lld\n", get(1, 1, n, l, r).max_sum);
        }
    }
    
    return 0;
}