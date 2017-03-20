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

const int me = 1000025;

int n, q, l, r;
int a[me], to[me], last[me];
long long sum[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    to[n + 1] = n;
    for(int i = n; i >= 1; i --){
        to[i] = to[i + 1];
        if(last[a[i]] != 0)
            to[i] = min(to[i], last[a[i]] - 1);
        last[a[i]] = i;
    }
    for(int i = 1; i <= n; i ++)
        sum[to[i] - i + 1] ++;
    for(int i = n; i > 0; i --)
        sum[i] += sum[i + 1];
    for(int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + sum[i];
    scanf("%d", &q);
    while(q --){
        scanf("%d%d", &l, &r);
        printf("%lld\n", sum[r] - sum[l - 1]);
    }
    
    return 0;
}
