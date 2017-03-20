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

int n, m;
int type, l, r;
int st[me << 2], lazy[me << 2];

void push(int I, int low, int high){
    if(lazy[I]){
        st[I] = high - low + 1 - st[I];
        if(low != high){
            lazy[I + I] ^= 1;
            lazy[I + I + 1] ^= 1;
        }
        lazy[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r){
    push(I, low, high);
    if(low > r || high < l)
        return;
    if(low >= l && high <= r){
        lazy[I] ^= 1;
        push(I, low, high);
        return;
    }
    int mid = (low + high) >> 1;
    update(I + I, low, mid, l, r);
    update(I + I + 1, mid + 1, high, l, r);
    st[I] = st[I + I] + st[I + I + 1];
}
int get(int I, int low, int high, int l, int r){
    push(I, low, high);
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return get(I + I, low, mid, l, r)
    + get(I + I + 1, mid + 1, high, l, r);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = uget(), m = uget();
    while(m --){
        type = uget(), l = uget(), r = uget();
        if(type == 0){
            update(1, 1, n, l, r);
        }
        else{
            uput(get(1, 1, n, l, r));
        }
    }
    
    return 0;
}