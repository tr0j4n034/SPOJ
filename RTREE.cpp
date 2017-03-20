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

int n, q, root;
int depth[me], in[me], s[me];
vector<int> v[me];

void update(pair<int, int> &a, int x){
    if(x > a.second)
        a.first = a.second, a.second = x;
    else if(x > a.first)
        a.first = x;
}

void dfs(int x, int par, int d){
    depth[x] = d;
    in[x] = d;
    for(int i : v[x]){
        if(i == par)
            continue;
        dfs(i, x, d + 1);
        in[x] = max(in[x], in[i]);
    }
    pair<int, int> up(depth[x], depth[x]);
    for(int i : v[x]){
        if(i == par)
            continue;
        s[x] = max(s[x], s[i]);
        s[x] = max(s[x], in[x] - depth[x]);
        update(up, in[i]);
    }
    s[x] = max(s[x], up.first + up.second - 2 * depth[x]);
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i < n; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    scanf("%d", &root);
    dfs(root, -1, 0);
    
    scanf("%d", &q);
    while(q --){
        int x;
        scanf("%d", &x);
        printf("%d\n", s[x]);
    }
    
    return 0;
}
