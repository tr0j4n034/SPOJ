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

int n, q, x, y;
int par[me], rk[me], sz[me];
multiset<int> s;

int Find(int x){
    return x == par[x] ? x : par[x] = Find(par[x]);
}
void Union(int x, int y){
    int r1 = Find(x), r2 = Find(y);
    if(r1 == r2)
        return;
    if(rk[r1] < rk[r2])
        swap(r1, r2);
    if(rk[r1] == rk[r2])
        rk[r1] ++;
    s.erase(s.find(sz[r1]));
    s.erase(s.find(sz[r2]));
    sz[r1] += sz[r2];
    s.insert(sz[r1]);
    par[r2] = r1;
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++){
        par[i] = i;
        sz[i] = 1;
        s.insert(1);
    }
    while(q --){
        scanf("%d%d", &x, &y);
        Union(x, y);
        printf("%d\n", *(--s.end()) - *(s.begin()));
    }
    
    return 0;
}
