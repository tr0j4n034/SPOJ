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
#include <set>
#include <map>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1025;

int n, m, a, b;
int dis[me];
vector<pair<int, int> > edges[me];
vector<int> cities[2];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    while(scanf("%d%d%d%d", &n, &m, &a, &b) != EOF){
        if(n + m == 0)
            break;
        cities[0].clear();
        cities[1].clear();
        for(int i = 0; i < a; i ++){
            int x;
            scanf("%d", &x);
            cities[0].push_back(x);
        }
        for(int i = 0; i < b; i ++){
            int x;
            scanf("%d", &x);
            cities[1].push_back(x);
        }
        for(int i = 0; i < n + 2; i ++)
            edges[i].clear();
        for(int i : cities[0]){
            edges[i].push_back(make_pair(n, 0));
            edges[n].push_back(make_pair(i, 0));
        }
        for(int i : cities[1]){
            edges[i].push_back(make_pair(n + 1, 0));
            edges[n + 1].push_back(make_pair(i, 0));
        }
        while(m --){
            int u, v, l;
            scanf("%d%d%d", &u, &v, &l);
            edges[u].push_back(make_pair(v, l));
            edges[v].push_back(make_pair(u, l));
        }
        for(int i = 0; i < n + 2; i ++)
            dis[i] = 1 << 30;
        dis[n] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        Q.push(make_pair(0, n));
        while(!Q.empty()){
            pair<int, int> cur = Q.top();
            Q.pop();
            if(cur.first > dis[cur.second])
                continue;
            for(auto i : edges[cur.second]){
                if(dis[i.first] > cur.first + i.second){
                    dis[i.first] = cur.first + i.second;
                    Q.push(make_pair(dis[i.first], i.first));
                }
            }
        }
        printf("%d\n", dis[n + 1]);
    }
    
    return 0;
}
