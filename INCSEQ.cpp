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

const int me = 100025;
const int sz = 51;
const int mod = 5000000;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int n, k;
int a[me], ft[sz][me];

void add(int* ft, int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        add(ft[pos], value);
}
int get(int* ft, int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        add(s, ft[pos]);
    return s;
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
    
    n = uget(), k = uget();
    for(int i = 0; i < n; i ++)
        a[i] = uget() + 1;
    for(int i = 0; i < n; i ++){
        for(int j = k; j > 1; j --)
            add(ft[j], a[i], get(ft[j - 1], a[i] - 1));
        add(ft[1], a[i], 1);
    }
    uput(get(ft[k], me - 1));
    
    return 0;
}
