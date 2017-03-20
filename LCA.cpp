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

const int me = 100025;
const int MAX_LOG = 19;

int n, q;
int par[MAX_LOG][me], depth[me];
vector<int> v[me];

void dfs(int node, int p){
    par[0][node] = p;
    for(int i : v[node]){
        if(i == p)
            continue;
        depth[i] = depth[node] + 1;
        dfs(i, node);
    }
}
int LCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = par[i][a];
    if(a == b)
        return a;
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(par[i][a] != -1 && par[i][a] != par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    return par[0][a];
}
/*
 12
 1 2
 1 5
 2 3
 2 4
 4 10
 5 6
 5 11
 11 12
 6 7
 6 8
 6 9
 */
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    int t = uget();
    for(int c = 1; c <= t; c ++){
        n = uget();
        for(int i = 1; i <= n; i ++)
            v[i].clear();
        for(int i = 1; i <= n; i ++){
            int l = uget();
            while(l --){
                int a = uget();
                v[i].push_back(a);
            }
        }
        dfs(1, -1);
        for(int i = 1; i < MAX_LOG; i ++)
            for(int j = 1; j <= n; j ++)
                if(par[i - 1][j] != -1)
                    par[i][j] = par[i - 1][par[i - 1][j]];
        printf("Case %d:\n", c
               );
        q = uget();
        while(q --){
            int a = uget(), b = uget();
            uput(LCA(a, b));
        }
    }
    
    return 0;
}
