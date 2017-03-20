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

const int me = 100025;

int uget()
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

int t, n, m;
int mst;
vector<pair<int, pair<int, int>> > v;
int par[me];

int Get(long long x){
    for(int i = 63; i > 0; i --){
        if(x & (1LL << i))
            return i;
    }
    return 0;
}
int Find(int x){
    return x == par[x] ? x : par[x] = Find(par[x]);
}
void Union(pair<int, pair<int, int>> edge){
    int x = edge.second.first;
    int y = edge.second.second;
    int l = edge.first;
    int r1 = Find(x), r2 = Find(y);
    if(r1 == r2)
        return;
    mst += l;
    if(rand() & 1)
        swap(r1, r2);
    par[r1] = r2;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    t = uget();
    while(t --){
        n = uget();
        m = uget();
        v.clear();
        while(m --){
            int a = uget(), b = uget();
            long long c;
            scanf("%lld", &c);
            v.push_back(make_pair(Get(c), make_pair(a, b)));
        }
        for(int i = 1; i <= n; i ++)
            par[i] = i;
        mst = 0;
        sort(v.begin(), v.end());
        for(auto i : v){
            Union(i);
        }
        uput(mst + 1);
    }
    
    return 0;
}
