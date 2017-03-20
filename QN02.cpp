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

int N, M, Q;
int comps;
int id[me], used[me];
vector<int> v[me];

void dfs(int node){
    id[node] = comps;
    used[node] = 1;
    for(int i : v[node])
        if(!used[i])
            dfs(i);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= N; i ++)
        if(!used[i]){
            comps ++;
            dfs(i);
        }
    
    scanf("%d", &Q);
    while(Q --){
        int a, b;
        scanf("%d%d", &a, &b);
        puts(id[a] == id[b] ? "YES" : "NO");
    }
    
    return 0;
}
