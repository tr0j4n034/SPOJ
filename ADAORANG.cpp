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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 450025;
const int sz = 255;
const int LOG = 20;

template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int T, N, Q, R, A, B;
int color[me], depth[me], par[LOG][me];
vector<int> edges[me];
bitset<sz> s[me];

void dfs(int node, int parent){
    s[node][color[node]] = 1;
    for(int i : edges[node]){
        if(i == parent)
            continue;
        depth[i] = depth[node] + 1;
        par[0][i] = node;
        dfs(i, node);
        s[node] |= s[i];
    }
}
int LCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = LOG - 1; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = par[i][a];
    if(a == b)
        return a;
    for(int i = LOG - 1; i >= 0; i --)
        if(par[i][a] != -1 && par[i][a] != par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    return par[0][a];
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
   
    fastInput(T);
    for(int cases = 0; cases < T; cases ++){
        fastInput(N);
        fastInput(Q);
        fastInput(R);
        for(int i = 0; i < N; i ++){
            edges[i].clear();
            s[i].reset();
        }
        for(int i = 0; i < LOG; i ++)
            for(int j = 0; j < N; j ++)
                par[i][j] = -1;
        for(int i = 0; i < N; i ++)
            fastInput(color[i]);
        for(int i = 1; i < N; i ++){
            fastInput(A);
            fastInput(B);
            edges[A].push_back(B);
            edges[B].push_back(A);
        }
        depth[R] = 0;
        dfs(R, -1);
        for(int i = 1; i < LOG; i ++)
            for(int j = 0; j < N; j ++)
                if(par[i - 1][j] != -1)
                    par[i][j] = par[i - 1][par[i - 1][j]];
        while(Q --){
            fastInput(A);
            fastInput(B);
            int L = LCA(A, B);
            printf("%d\n", (int)s[L].count());
        }
    }
    
    return 0;
}
