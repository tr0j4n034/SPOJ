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
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bitset>

using namespace std;

const int me = 1025;
/*
 in i steps
 looking every snowball at most j times
 we can solve for
 dp[i][j] = dp[i - 1][j] + 2 * dp[i - 1][j - 1]
 and +1 extra ball
 */

unsigned long long N;
int K;
map<pair<int, int>, unsigned long long> dp;

unsigned long long get(int steps, int k){
    if(dp.count(make_pair(steps, k)) != 0)
        return dp[make_pair(steps, k)];
    unsigned long long result = 0;
    if(k == 0)
        result = 0;
    else if(k == 1)
        result = 2 * steps;
    else if(k == 2)
        result = 2LL * steps * steps;
    else if(k == 3)
        result = (4LL * (steps - 1) * (steps - 1) * (steps - 1) + 6LL * (steps - 1) * (steps - 1) + 8LL * (steps - 1) + 6) / 3;
    else if(k > steps)
        result = get(steps, steps);
    else if(steps == 1)
        result = 2;
    else result = min(N, (2 * get(steps - 1, k - 1) + 2) + get(steps - 1, k));
    return dp[make_pair(steps, k)] = result;
}
long long solve(long long N, int K){
    if(K == 1)
        return N / 2;
    if(K == 2){
        N /= 2;
        int low = 0, high = 1 << 30, mid, best = high;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            if(1LL * mid * mid >= N){
                best = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return best;
    }
    else if(K == 3){
        int low = 0, high = 1000000, mid, best = high;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            unsigned long long to = (4LL * (mid - 1) * (mid - 1) * (mid - 1) + 6LL * (mid - 1) * (mid - 1) + 8LL * (mid - 1) + 6) / 3;
            if(to + 1 >= N){
                best = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return best;
    }
    if(N == 1)
        return 0;
    for(int i = 1; ; i ++)
        if(get(i, K) + 1 >= N)
            return i;
    return -1;
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> N >> K;
    cout << solve(N, K) << endl;
    for(int i = 16; i <= 15; i ++)
        for(int j = 1; j < 8; j ++)
            cout << i << " " << j << " ---> " << get(i, j) << endl;
    return 0;
}
