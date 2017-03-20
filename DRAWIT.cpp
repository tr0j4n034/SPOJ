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

int T, N, M;
int used[me], degree[me];
vector<int> edges[me];

void dfs(int node){
    used[node] = 1;
    for(int i : edges[node]){
        if(used[i])
            continue;
        dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    for(int i = 0; i < T; i ++){
        cin >> N >> M;
        
        for(int i = 1; i <= N; i ++)
            edges[i].clear();
        for(int i = 1; i <= N; i ++)
            degree[i] = 0;
        
        for(int i = 0; i < M; i ++){
            int u, v, c;
            cin >> u >> v >> c;
            edges[u].push_back(v);
            edges[v].push_back(u);
            degree[u] += c;
            degree[v] += c;
        }
        dfs(1);
        
        int good = 1;
        for(int i = 1; i <= N; i ++){
            if(!used[i])
                good = 0;
        }
        if(!good){
            cout << "NO" << endl;
            continue;
        }
        int odd = 0;
        for(int i = 1; i <= N; i ++)
            if(degree[i] & 1)
                odd ++;
        
        if(odd > 2){
            cout << "NO" << endl;
        }
        else if(odd == 0){
            cout << "YES " << 1 << endl;
        }
        else{
            int result = -1;
            for(int i = 1; i <= N; i ++){
                if(degree[i] & 1){
                    result = i;
                    break;
                }
            }
            cout << "YES " << result << endl;
        }
    }
    
    return 0;
}
