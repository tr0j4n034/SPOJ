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

const int me = 200025;

int n, q, type, l, r;
int a[me], st[me << 2][3], lazy[me << 2], h[3];

void add(int &a, int b){
    a += b;
    if(a > 2)
        a -= 3;
}
void rotate(int I){
    h[1] = st[I][0], h[2] = st[I][1], h[0] = st[I][2];
    st[I][0] = h[0], st[I][1] = h[1], st[I][2] = h[2];
}
void build(int I, int low, int high){
    if(low == high){
        st[I][0] = 1;
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    st[I][0] = high - low + 1;
}
void push(int I){
    if(lazy[I]){
        add(lazy[I + I], lazy[I]);
        add(lazy[I + I + 1], lazy[I]);
        while(lazy[I] > 0){
            rotate(I);
            lazy[I] --;
        }
    }
}
void update(int I, int low, int high, int l, int r){
    push(I);
    if(low > r || high < l)
        return;
    if(low >= l && high <= r){
        lazy[I] ++;
        push(I);
        return;
    }
    int mid = (low + high) >> 1;
    update(I + I, low, mid, l, r);
    update(I + I + 1, mid + 1, high, l, r);
    for(int i = 0; i < 3; i ++)
        st[I][i] = st[I + I][i] + st[I + I + 1][i];
}
int get(int I, int low, int high, int l, int r){
    push(I);
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I][0];
    int mid = (low + high) >> 1;
    return get(I + I, low, mid, l, r)
    + get(I + I + 1, mid + 1, high, l, r);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = uget(), q = uget();
    build(1, 0, n - 1);
    while(q --){
        type = uget(), l = uget(), r = uget();
        if(type == 0){
            update(1, 0, n - 1, l, r);
        }
        else{
            uput(get(1, 0, n - 1, l, r));
        }
    }
    
    return 0;
}
