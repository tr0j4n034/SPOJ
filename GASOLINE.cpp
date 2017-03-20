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

const int me = 525;
const int oo = 1234567;

int T, N, M;
int result;
int dis[me];
vector<pair<int, int>> edges[me];

void dijkstra(int node){
    fill(dis, dis + N, oo);
    dis[node] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, node));
    
    while(!Q.empty()){
        pair<int, int> cur = Q.top();
        Q.pop();
        int D = cur.first;
        int W = cur.second;
        
        if(D > dis[W])
            continue;
        for(auto i : edges[W]){
            if(dis[i.first] > D + i.second){
                dis[i.first] = D + i.second;
                Q.push(make_pair(dis[i.first], i.first));
            }
        }
    }
    result = max(result, *max_element(dis, dis + N));
}


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fastInput(T);
    
    while(T --){
        fastInput(N);
        fastInput(M);
        for(int i = 0; i < N; i ++)
            edges[i].clear();
        for(int i = 0; i < M; i ++){
            int u, v, l;
            fastInput(u);
            fastInput(v);
            fastInput(l);
            edges[u].push_back(make_pair(v, l));
            edges[v].push_back(make_pair(u, l));
        }
        
        result = 0;
        for(int i = 0; i < N && result != oo; i ++){
            dijkstra(i);
        }
        if(result == oo)
            result = -1;
        printf("%d\n", result);
    }
    
    return 0;
}
