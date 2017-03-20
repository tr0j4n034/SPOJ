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

int n, t;
long long m;
int a[me], b[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d%lld", &n, &m);
        for(int i = 0; i < n; i ++)
            scanf("%d%d", &a[i], &b[i]);
        long long low = 1, high = 1LL << 40, mid, best = 1;
        while(low <= high){
            mid = (low + high) >> 1;
            long long s = m;
            for(int i = 0; i < n && s >= 0; i ++){
                if(a[i] < mid)
                    s -= 1LL * b[i] * (mid - a[i]);
            }
            if(s >= 0){
                best = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        printf("%lld\n", best);
    }
    
    return 0;
}