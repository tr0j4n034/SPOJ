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

const int me = 10025;
const int MAX_LOG = 15;

int N, Q;
int a, b;
int depth[me], par[me][MAX_LOG];
vector<int> edges[me];

void dfs(int node, int parent){
    for(int i : edges[node]){
        if(i == parent)
            continue;
        par[i][0] = node;
        depth[i] = depth[node] + 1;
        dfs(i, node);
    }
}
int lca(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = par[a][i];
    if(a == b)
        return a;
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    return par[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i < N; i ++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, -1);
    
    for(int i = 1; i < MAX_LOG; i ++)
        for(int j = 1; j <= N; j ++)
            if(par[j][i - 1])
                par[j][i] = par[par[j][i - 1]][i - 1];
    
    cin >> Q;
    while(Q --){
        cin >> a >> b;
        
        if(depth[a] < depth[b])
            cout << "NO" << endl;
        else cout << "YES " << lca(a, b) << endl;
    }
    
    
    return 0;
}
