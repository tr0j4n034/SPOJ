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

const int me = 100025;
const int MAX_LOG = 20;

int n, q, t;
char type[10];
int par[MAX_LOG][me], sum[MAX_LOG][me], depth[me];
vector<pair<int, int>> v[me];

void dfs(int node, int p){
    par[0][node] = p;
    for(auto i : v[node]){
        if(i.first == p)
            continue;
        depth[i.first] = depth[node] + 1;
        sum[0][i.first] = i.second;
        dfs(i.first, node);
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
int get(int a, int k){
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(k > (1 << i)){
            a = par[i][a];
            k -= (1 << i);
        }
    return a;
}
int get_length(int a, int k){
    int l = 0;
    for(int i = MAX_LOG - 1; i >= 0; i --){
        if(k >= (1 << i)){
            l += sum[i][a];
            a = par[i][a];
            k -= (1 << i);
        }
    }
    return l;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    t = uget();
    for(int c = 0; c < t; c ++){
        n = uget();
        for(int i = 1; i <= n; i ++)
            v[i].clear();
        for(int i = MAX_LOG - 1; i >= 0; i --)
            for(int j = 1; j <= n; j ++){
                par[i][j] = -1;
                sum[i][j] = 0;
            }
        for(int i = 1; i < n; i ++){
            int a = uget(), b = uget(), c = uget();
            v[a].push_back(make_pair(b, c));
            v[b].push_back(make_pair(a, c));
        }
        dfs(1, -1);
        for(int i = 1; i < MAX_LOG; i ++)
            for(int j = 1; j <= n; j ++)
                if(par[i - 1][j] != -1){
                    par[i][j] = par[i - 1][par[i - 1][j]];
                    sum[i][j] = sum[i - 1][j] + sum[i - 1][par[i - 1][j]];
                }
        while(scanf(" %s", type) != EOF){
            if(type[1] == 'O')
                break;
            if(type[1] == 'I'){
                int a = uget(), b = uget();
                int lca = LCA(a, b);
                uput(get_length(a, depth[a] - depth[lca]) + get_length(b, depth[b] - depth[lca]));
            }
            else{
                int a = uget(), b = uget(), k = uget();
                
                int lca = LCA(a, b);
                int l = depth[a] + depth[b] - 2 * depth[lca] + 1;
                if(depth[a] - depth[lca] + 1 >= k)
                    uput(get(a, k));
                else uput(get(b, l - k + 1));
            }
        }
        if(c < t - 1)
            putchar('\n');
    }
    
    return 0;
}
