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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;

int n, m, q, x, y;
char type;
int par[me], sz[me];

int Find(int x){
    return x == par[x] ? x : par[x] = Find(par[x]);
}
void Union(int x, int y){
    int r1 = Find(x);
    int r2 = Find(y);
    if(r1 == r2)
        return;
    if(sz[r1] + sz[r2] > m)
        return;
    if(rand() & 1){
        par[r1] = r2;
        sz[r2] += sz[r1];
    }
    else{
        par[r2] = r1;
        sz[r1] += sz[r2];
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i ++){
        par[i] = i;
        sz[i] = 1;
    }
    while(q --){
        scanf(" %c", &type);
        if(type == 'S'){
            scanf("%d", &x);
            printf("%d\n", sz[Find(x)]);
        }
        else if(type == 'E'){
            scanf("%d%d", &x, &y);
            printf(Find(x) == Find(y) ? "Yes\n" : "No\n");
        }
        else{
            scanf("%d%d", &x, &y);
            Union(x, y);
        }
    }
    
    return 0;
}