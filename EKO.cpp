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

const int me = 1000025;

int n, t = 1;
long long m;
int a[me];
long long pref[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    while(t --){
        scanf("%d%lld", &n, &m);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        pref[0] = a[0];
        for(int i = 1; i < n; i ++)
            pref[i] = pref[i - 1] + a[i];
        pref[n] = pref[n - 1];
        long long low = 1, high = 1LL << 50, mid, best = 1;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            auto pos = upper_bound(a, a + n, mid) - a;
            long long s = (pref[n - 1] - pref[pos] + a[pos]) - mid * (n - pos);
            if(s >= m){
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