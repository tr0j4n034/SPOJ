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

int t, n;
long long m;
int a[me], cnt[me];

bool check(long long s){
    fill(cnt, cnt + me, 0);
    for(int i = 1; i <= n; i ++)
        cnt[a[i]] ++;
    long long has = m;
    for(int i = me - 1; i > 0 && has > 0 && s > 0; i --){
        if(!cnt[i])
            continue;
        long long take = min(has, 1LL * cnt[i]);
        s -= take * i;
        has -= take;
        cnt[i] -= take;
        cnt[i - 1] += take;
    }
    return (s <= 0 && has >= 0) ? true : false;
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        scanf("%lld", &m);
        long long low = 1, high = 1LL << 62, mid, best = 1;
        while(low <= high){
            mid = (low + high + 1) / 2;
            if(check(mid)){
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
