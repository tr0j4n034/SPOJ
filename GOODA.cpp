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

const int me = 1000025;

int N, M, S, E;
int comp_count;
int f[me], used[me], comp_id[me];
long long has[me], result[me];
vector<int> dfs_list;
vector<int> v[me], gv[me];


void dfs1(int node){
    used[node] = 1;
    for(int i : v[node]){
        if(!used[i])
            dfs1(i);
    }
    dfs_list.push_back(node);
}
void dfs2(int node){
    used[node] = 1;
    comp_id[node] = comp_count;
    has[comp_count] += f[node];
    for(int i : gv[node]){
        if(!used[i])
            dfs2(i);
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &E);
    for(int i = 1; i <= N; i ++)
        scanf("%d", &f[i]);
    for(int i = 0; i < M; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        gv[b].push_back(a);
    }
    for(int i = 1; i <= N; i ++){
        if(!used[i])
            dfs1(i);
    }
    reverse(dfs_list.begin(), dfs_list.end());
    fill(used, used + N + 1, 0);
    for(int i : dfs_list){
        if(!used[i]){
            comp_count ++;
            dfs2(i);
        }
    }
    fill(used, used + comp_count + 1, 0);
    for(int i = 1; i <= comp_count; i ++)
        v[i].clear();
    for(int i = 1; i <= N; i ++)
        for(int j : gv[i])
            if(comp_id[i] != comp_id[j])
                v[comp_id[j]].push_back(comp_id[i]);
    //for(int i = 1; i <= N; i ++)
      //  cout << i << " ---> " << comp_id[i] << endl;
    //for(int i = 1; i <= comp_count; i ++)
      //  cout << i << " ---> has = " << has[i] << endl;
    fill(used, used + comp_count + 1, 0);
    queue<int> Q;
    Q.push(comp_id[S]);
    result[comp_id[S]] = has[comp_id[S]];
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        used[node] = 1;
        for(int i : v[node]){
            if(used[i])
                continue;
            if(result[i] < result[node] + has[i]){
                result[i] = result[node] + has[i];
                Q.push(i);
            }
        }
    }
    cout << result[comp_id[E]] << endl;
    
    return 0;
}
