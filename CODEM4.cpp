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

const int me = 125;

int t, n;
long long ms;
long long a[me], pref[me], dp[me][me];

long long get(int low, int high){
    if(low > high)
        return 0;
    if(dp[low][high] != -1)
        return dp[low][high];
    long long &x = dp[low][high];
    if(low == high)
        return x = a[low];
    return x = max(pref[high] - pref[low] - get(low + 1, high) + a[low],
                   pref[high - 1] - pref[low - 1] - get(low, high - 1) + a[high]);
}
long long go(int low, int high){
    if(low > high)
        return 0;
    if(dp[low][high] != -1)
        return dp[low][high];
    long long &x = dp[low][high];
    if(low == high)
        return x = a[low];
    return x = max(a[low] + max(go(low + 1, high - 1), go(low + 2, high)),
                   a[high] + max(go(low + 1, high - 1), go(low, high - 2)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 1; i <= n; i ++)
            cin >> a[i];
        // dumb
        ms = 0;
        for(int i = 1; i <= n; i ++)
            for(int j = i; j <= n; j ++)
                dp[i][j] = -1;
        ms = go(1, n);
        // smart
        for(int i = 1; i <= n; i ++)
            pref[i] = pref[i - 1] + a[i];
        for(int i = 1; i <= n; i ++)
            for(int j = i; j <= n; j ++)
                dp[i][j] = -1;
        cout << ms << " " << get(1, n) << endl;
    }
    
    return 0;
}
