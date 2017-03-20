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

const int me = 125;
const int sz = 5025;

template <class T> void FastInput(T &n){
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

int T, N, E, S;
int components;
int d[me], id[me], used[me], component_sum[me], component_length[me];
int dp[sz];
vector<pair<pair<int, int>, int>> edge_list;
vector<int> dfs_list;
vector<pair<int, int>> edges[me], rev[me];

void dfs1(int node){
    used[node] = 1;
    for(pair<int, int> i : edges[node]){
        if(used[i.first])
            continue;
        dfs1(i.first);
    }
    dfs_list.push_back(node);
}
void dfs2(int node){
    used[node] = 1;
    id[node] = components;
    for(pair<int, int> i : rev[node]){
        if(used[i.first])
            continue;
        dfs2(i.first);
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    FastInput(T);
    for(int cases = 0; cases < T; cases ++){
        FastInput(N);
        FastInput(E);
        FastInput(S);
        
        for(int i = 1; i <= N; i ++)
            FastInput(d[i]);
        for(int i = 1; i <= N; i ++){
            edges[i].clear();
            rev[i].clear();
        }
        dfs_list.clear();
        edge_list.clear();
        
        fill(id, id + N + 1, 0);
        fill(used, used + N + 1, 0);
        
        for(int i = 1; i <= E; i ++){
            int u, v, l;
            
            FastInput(u);
            FastInput(v);
            FastInput(l);
            
            edge_list.push_back(make_pair(make_pair(u, v), l));
            edges[u].push_back(make_pair(v, l));
            rev[v].push_back(make_pair(u, l));
        }
    
        for(int i = 1; i <= N; i ++){
            if(!used[i]){
                dfs1(i);
            }
        }
        
        reverse(dfs_list.begin(), dfs_list.end());
        fill(used, used + N + 1, 0);
        
        components = 0;
        for(int i : dfs_list){
            if(!used[i]){
                components ++;
                dfs2(i);
            }
        }
        //for(int i = 1; i <= N; i ++)
          //  cout << i << " ---> " << id[i] << endl;
        
        for(int i = 1; i <= components; i ++){
            component_sum[i] = 0;
            component_length[i] = 0;
        }
        for(int i = 1; i <= N; i ++){
            component_sum[id[i]] += d[i];
        }
        for(auto i : edge_list){
            int u = i.first.first;
            int v = i.first.second;
            int l = i.second;
            
            if(id[u] == id[v])
                component_length[id[u]] += l;
        }
        fill(dp, dp + S + 1, -1);
        dp[0] = 0;
        
        for(int i = 1; i <= components; i ++){
            if(component_length[i] > S || component_sum[i] < 1)
                continue;
            for(int j = S; j >= component_length[i]; j --)
                if(dp[j - component_length[i]] != -1)
                    dp[j] = max(dp[j], dp[j - component_length[i]] + component_sum[i]);
        }
        int ans = *max_element(dp, dp + S + 1);
        
        printf("Case %d: %d\n", cases + 1, ans);
    }

    
    return 0;
}

/*
 1
 3 3 3
 3 3 3
 1 2 3
 2 3 3
 2 1 3
 
 
 1
 4 4 10
 4 6 7 5
 1 3 5
 3 4 5
 4 1 7
 1 2 8
 
 */
