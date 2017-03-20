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
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 30025;
const int sz = 10025;
const int BLOCKS = 75;
const int BLOCK_SIZE = 415;

int n, q;
int type, l, r, x;
int a[me], ft[BLOCKS][sz];

void add(int *ft, int pos, int value){
    for( ; pos < sz; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int *ft, int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
int get(int *ft, int l, int r){
    return get(ft, r) - get(ft, l - 1);
}


static int uget()
{
    int c;
    while(c=getchar(), isspace(c)) {}
    int n = c-'0';
    while(c=getchar(), isdigit(c)) { n=n*10 + (c-'0'); }
    return n;
}
template<class T> static void uput(T n)
{
    char s[30];
    int x = 0;
    do { s[x++]=(n%10)+'0'; n/=10; } while(n);
    for(int i=x-1; i>=0; i--) putchar(s[i]);
    putchar('\n');
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = uget();
    for(int i = 1; i <= n; i ++)
        a[i] = uget();
    for(int i = 1; i <= n; i ++)
        add(ft[i / BLOCK_SIZE], a[i], 1);
    q = uget();
    while(q --){
        type = uget();
        if(type == 0){
            l = uget(), x = uget();
            add(ft[l / BLOCK_SIZE], a[l], -1);
            a[l] = x;
            add(ft[l / BLOCK_SIZE], a[l], 1);
        }
        else{
            l = uget(), r = uget(), x = uget();
            int ans = 0;
            for( ; l <= r && l % BLOCK_SIZE > 0; l ++)
                if(a[l] > x)
                    ans ++;
            for( ; l + BLOCK_SIZE <= r; l += BLOCK_SIZE)
                ans += BLOCK_SIZE - get(ft[l / BLOCK_SIZE], x);
            for( ; l <= r; l ++)
                if(a[l] > x)
                    ans ++;
            uput(ans);
        }
    }
    
    return 0;
}
