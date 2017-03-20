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
const int INF = 1 << 29;

struct node{
    int first;
    int second;
    node() {}
    node(int first, int second) : first(first), second(second) {}
};

void merge(node &a, node b, node c){
    if(b.first > c.first)
        a = node(b.first, max(b.second, c.first));
    else a = node(c.first, max(b.first, c.second));
}

int n, q, x, y;
char type;
int a[me];
node st[me << 2];

void build(int I, int low, int high){
    if(low == high){
        st[I] = node(a[low], -INF);
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    merge(st[I], st[I + I], st[I + I + 1]);
}
void update(int I, int low, int high, int pos, int value){
    if(low == high && low == pos){
        st[I] = node(value, -INF);
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(I + I, low, mid, pos, value);
    else update(I + I + 1, mid + 1, high, pos, value);
    merge(st[I], st[I + I], st[I + I + 1]);
}
node get(int I, int low, int high, int l, int r){
    if(low > high || low > r || high < l)
        return node(-INF, -INF);
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    node a;
    merge(a, get(I + I, low, mid, l, r), get(I + I + 1, mid + 1, high, l, r));
    return a;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &q);
    while(q --){
        scanf(" %c%d%d", &type, &x, &y);
        if(type == 'U'){
            update(1, 1, n, x, y);
        }
        else{
            node a = get(1, 1, n, x, y);
            printf("%d\n", a.first + a.second);
        }
    }
    
    return 0;
}