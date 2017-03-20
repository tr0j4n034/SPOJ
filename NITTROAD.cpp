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

const int me = 20025;

int cases, NumberOfCities, Queries;
int SumOfSquares;
int a[me], b[me], q[me], mark[me], parent[me], rk[me], size[me], ans[me];

int Find(int x){
    return x == parent[x] ? x : parent[x] = Find(parent[x]);
}
void Union(int x, int y){
    int rootx = Find(x);
    int rooty = Find(y);
    if(rootx == rooty)
        return;
    if(rk[rooty] > rk[rootx])
        swap(rootx, rooty);
    if(rk[rootx] == rk[rooty])
        rk[rootx] ++;
    parent[rooty] = rootx;
    SumOfSquares -= size[rootx] * size[rootx] + size[rooty] * size[rooty];
    size[rootx] += size[rooty];
    SumOfSquares += size[rootx] * size[rootx];
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &cases);
    while(cases --){
        scanf("%d", &NumberOfCities);
        for(int i = 1; i < NumberOfCities; i ++){
            scanf("%d%d", &a[i], &b[i]);
        }
        for(int i = 1; i < NumberOfCities; i ++)
            mark[i] = 0;
        scanf("%d", &Queries);
        for(int i = 1; i <= Queries; i ++){
            char type;
            int x = -1;
            scanf(" %c", &type);
            if(type == 'R')
                scanf("%d", &x);
            q[i] = x;
            mark[x] = 1;
        }
        for(int i = 1; i <= NumberOfCities; i ++){
            parent[i] = i;
            size[i] = 1;
            rk[i] = 0;
        }
        SumOfSquares = NumberOfCities;
        for(int i = 1; i < NumberOfCities; i ++)
            if(!mark[i]){
                Union(a[i], b[i]);
            }
        for(int i = Queries; i > 0; i --){
            if(q[i] == -1){
                ans[i] = (NumberOfCities * NumberOfCities - SumOfSquares) / 2;
            }
            else{
                Union(a[q[i]], b[q[i]]);
            }
        }
        for(int i = 1; i <= Queries; i ++){
            if(q[i] == -1)
                printf("%d\n", ans[i]);
        }
        if(cases > 0)
            printf("\n");
    }
    
    return 0;
}
