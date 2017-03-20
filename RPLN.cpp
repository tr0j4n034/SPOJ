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
const int MAX_LOG = 20;

int t, n, q, l, r;
int a[me], st[me][MAX_LOG];

int get(int l, int r){
    int lg = 31 - __builtin_clz(r - l + 1);
    return min(st[l][lg], st[r - (1 << lg) + 1][lg]);
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    for(int c = 0; c < t; c ++){
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i ++)
            st[i][0] = a[i];
        for(int i = 1; i < MAX_LOG; i ++)
            for(int j = 1; j + (1 << i) - 1 <= n; j ++)
                st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        printf("Scenario #%d:\n", c + 1);
        while(q --){
            scanf("%d%d", &l, &r);
            printf("%d\n", get(l, r));
        }
    }
    
    
    return 0;
}
