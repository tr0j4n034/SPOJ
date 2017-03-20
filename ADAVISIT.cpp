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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 400025;
const int LOG = 19;

int N;
int timer;
int depth[me], self[me][2], has[me][2], par[me][LOG];
vector<int> edges[me];

void dfs(int node, int parent){
    par[node][0] = parent;
    depth[node] = depth[parent] + 1;
    for(int i : edges[node]){
        if(i == parent)
            continue;
        dfs(i, node);
    }
}
int LCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = LOG - 1; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = par[a][i];
    if(a == b)
        return a;
    for(int i = LOG - 1; i >= 0; i --)
        if(par[a][i] != 0 && par[b][i] != 0 && par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    return par[a][0];
}
int Kth_parent(int a, int k){
    if(k >= depth[a])
        return 0;
    for(int i = LOG - 1; i >= 0; i --)
        if(k >= (1 << i)){
            a = par[a][i];
            k -= (1 << i);
        }
    return a;
}
void collect(int node, int parent){
    has[node][0] = self[node][0];
    has[node][1] = self[node][1];
    for(int i : edges[node]){
        if(i == parent)
            continue;
        collect(i, node);
        has[node][0] += has[i][0];
        has[node][1] += has[i][1];
    }
}
int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &N);
    for(int i = 1; i < N; i ++){
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0);
    cout << endl;
    for(int i = 1; i < LOG; i ++)
        for(int j = 1; j <= N; j ++)
            if(par[j][i - 1] != 0)
                par[j][i] = par[par[j][i - 1]][i - 1];
    for(int i = 2; i <= N; i ++){
        int L = LCA(i - 1, i);
        if(L == i){
            self[i][0] ++;
            self[i - 1][1] ++;
        }
        else if(L == i - 1){
            self[i - 1][0] ++;
            self[i][1] ++;
        }
        else{
            self[L][0] ++;
            self[i - 1][1] ++;
            int SL = Kth_parent(i, depth[i] - depth[L] - 1);
            self[SL][0] ++;
            self[i][1] ++;
        }
    }
    collect(1, 0);
    for(int i = 1; i <= N; i ++){
        printf("%d\n", has[i][1] - has[i][0] + self[i][0]);
    }
    
    return 0;
}
