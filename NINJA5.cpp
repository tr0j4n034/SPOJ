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

const int me = 2000025;

int t, n, k, x;
int a[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d%d", &n, &k);
        fill(a, a + n + 5, 0);
        while(k --){
            scanf("%d", &x);
            a[x] = 1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i - 1] == 0 && a[i + 1] == 0)
                a[i] = 1;
            if(a[i] == 1)
                ans ++;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
