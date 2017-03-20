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
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;

int t, n, m, x;
int a[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    for(int c = 0; c < t; c ++){
        fill(a, a + me, 0);
        scanf("%d%d", &n, &m);
        while(m --){
            scanf("%d", &x);
            a[x] = 1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++)
            if(a[i] || a[i - 1] || a[i + 1])
                ans ++;
        printf("Case %d: %d\n", c + 1, ans);
    }
    
    return 0;
}
