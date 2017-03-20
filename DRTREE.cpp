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
const int MAX_LOG = 19;

int N, Q;
int root = 1;
int w[me], depth[me], par[me][MAX_LOG];
long long sum[me];
vector<int> v[me];

void dfs(int a, int par){
    sum[a] = w[a];
    for(int i : v[a]){
        if(i == par)
            continue;
        depth[i] = depth[a] + 1;
        dfs(i, a);
        sum[a] += sum[i];
    }
}
int GetLCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = par[a][i];
    if(a == b)
        return a;
    for(int i = MAX_LOG - 1; i >= 0; i --)
        if(par[a][i] != 0 && par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    return par[a][0];
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &N);
    for(int i = 1; i <= N; i ++)
        scanf("%d", &w[i]);
    for(int i = 2; i <= N; i ++){
        scanf("%d", &par[i][0]);
        v[par[i][0]].push_back(i);
    }
    for(int i = 1; i < MAX_LOG; i ++)
        for(int j = 1; j <= N; j ++)
            if(par[j][i - 1])
                par[j][i] = par[par[j][i - 1]][i - 1];
    dfs(1, -1);

    scanf("%d", &Q);
    while(Q --){
        char type;
        int x;
        
        scanf(" %c%d", &type, &x);
        if(type == 'R'){
            root = x;
        }
        else{
            if(root == x){
                printf("%lld\n", sum[1]);
                continue;
            }
            int lca = GetLCA(root, x);
            if(lca == x){
                int delta = depth[root] - depth[x] - 1;
                x = root;
                for(int i = MAX_LOG - 1; i >= 0; i --)
                    if(delta >= (1 << i)){
                        x = par[x][i];
                        delta -= (1 << i);
                    }
                printf("%lld\n", sum[1] - sum[x]);
            }
            else printf("%lld\n", sum[x]);
        }
    }
    
    return 0;
}
