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

const int me = 200025;

int t, n, k;
int pr[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fill(pr + 2, pr + me, 1);
    for(int i = 2; i < me; i ++)
        if(pr[i])
            for(int j = i + i; j < me; j += i)
                pr[j] = 0;
    scanf("%d", &t);
    while(t --){
        scanf("%d%d", &n, &k);
        if(k == 0){
            printf("%lld\n", 1LL * n * (n - 1) / 2);
            continue;
        }
        int s = 0, ptr = 1;
        long long ans = 0;
        for(int i = 2; i <= n; i ++){
            while(ptr < n && s < k){
                ++ptr;
                s += pr[ptr];
            }
            if(s >= k)
                ans += n - ptr + 1;
            s -= pr[i];
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}