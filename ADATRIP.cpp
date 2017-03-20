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

const int me = 500025;
const int oo = 1 << 30;

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

int N, M, Q;
int id[me];
pair<int, int> result[me];
vector<pair<int, int>> edges[me];

pair<pair<int, int>, vector<int>> Dijkstra(int node){
    vector<int> d(N + 1, oo);
    d[node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, node));
    while(!Q.empty()){
        pair<int, int> cur = Q.top();
        Q.pop();
        if(cur.first > d[cur.second])
            continue;
        for(auto i : edges[cur.second]){
            if(d[i.first] > cur.first + i.second){
                d[i.first] = cur.first + i.second;
                Q.push(make_pair(d[i.first], i.first));
            }
        }
    }
    int cnt = 0;
    int big = -1;
    for(int i = 0; i < N; i ++){
        if(d[i] == oo)
            continue;
        if(d[i] == big){
            cnt ++;
        }
        else if(d[i] > big){
            big = d[i];
            cnt = 1;
        }
    }
    return make_pair(make_pair(big, cnt), d);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fastInput(N);
    fastInput(M);
    fastInput(Q);
    
    for(int i = 0; i < M; i ++){
        int a, b, l;
        fastInput(a);
        fastInput(b);
        fastInput(l);
        edges[a].push_back(make_pair(b, l));
        edges[b].push_back(make_pair(a, l));
    }
    while(Q --){
        int x;
        fastInput(x);
        
        if(id[x] == 0){
            pair<pair<int, int>, vector<int>> g = Dijkstra(x);
            result[x] = g.first;
            id[x] = 1;
        }
        printf("%d %d\n", result[x].first, result[x].second);
    }
    
    return 0;
}
