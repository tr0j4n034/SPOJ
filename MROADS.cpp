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

const int me = 100025;

struct edge{
    int to;
    int length;
    int min_length;
    
    edge() {}
    edge(int to, int length, int min_length) : to(to), length(length), min_length(min_length) {}
};

int n, k;
int has;
int dis[me], maxdis[me];
vector<edge> v[me];

void dfs1(int x, int par){
    maxdis[x] = dis[x];
    for(auto i : v[x]){
        if(i.to == par)
            continue;
        dis[i.to] = dis[x] + i.length;
        dfs1(i.to, x);
        maxdis[x] = max(maxdis[x], maxdis[i.to]);
    }
}
bool dfs2(int x, int par, int relax, int D){
    if(has < 0)
        return false;
    if(maxdis[x] - relax - has > D)
        return false;
    if(maxdis[x] - relax <= D)
        return true;
    bool ok = true;
    for(auto i : v[x]){
        if(!ok)
            break;
        if(i.to == par)
            continue;
        if(maxdis[i.to] - relax <= D)
            continue;
        int need = maxdis[i.to] - relax - D;
        if(need > has)
            return false;
        int take = min(need, i.length - i.min_length);
        has -= take;
        ok &= dis[i.to] - relax - take <= D;
        ok &= dfs2(i.to, x, relax + take, D);
    }
    return ok;
}
/*
 2 10
 1 2 10 1
 */
int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i ++){
        int a, b, l1, l2;
        scanf("%d%d%d%d", &a, &b, &l1, &l2);
        v[a].push_back(edge(b, l1, l2));
        v[b].push_back(edge(a, l1, l2));
    }
    dfs1(1, -1);
    int low = 0, high = 1 << 30, mid, best = high;
    while(low <= high){
        mid = (low + high + 1) >> 1;
        has = k;
        if(dfs2(1, -1, 0, mid)){
            best = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    printf("%d\n", best);

    return 0;
}
