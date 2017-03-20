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

const int me = 200025;

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}
template<class T> static void uput(T n)
{
    char s[30];
    int x = 0;
    do { s[x ++]=(n % 10) + '0'; n /= 10; } while(n);
    for(int i = x - 1; i >= 0; i --) putchar(s[i]);
    putchar('\n');
}

struct node{
    long long sum;
    long long minimum;
    int cnt;
    node() {}
    node(long long sum, long long minimum, int cnt)
    : sum(sum), minimum(minimum), cnt(cnt) {}
    long long get(){
        return sum - minimum * cnt;
    }
};
void merge(node &a, node b, node c){
    a.minimum = min(b.minimum, c.minimum);
    a.sum = b.sum + c.sum;
    a.cnt = (a.minimum == b.minimum) ? b.cnt : 0;
    a.cnt += (a.minimum == c.minimum) ? c.cnt : 0;
}

int n, p;
long long a[me];
node st[me << 2];

void build(int I, int low, int high){
    if(low == high){
        st[I] = (node){a[low], a[low], 1};
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    merge(st[I], st[I + I], st[I + I + 1]);
}
void update(int I, int low, int high, int pos, int value){
    if(low == high){
        st[I].sum = st[I].minimum = (a[low] += value);
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
        return node(0, 1LL << 50, 1);
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    node ans;
    merge(ans, get(I + I, low, mid, l, r),
          get(I + I + 1, mid + 1, high, l, r));
    return ans;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        scanf("%lld", &a[i]);
    build(1, 0, n - 1);
    scanf("%d", &p);
    while(p --){
        char type[10];
        int l, r;
        scanf(" %s%d%d", type, &l, &r);
        if(type[0] == 'C')
            printf("%lld\n", (get(1, 0, n - 1, l, r)).get());
        else if(type[0] == 'G')
            update(1, 0, n - 1, r, l);
        else update(1, 0, n - 1, r, -l);
    }
    
    return 0;
}