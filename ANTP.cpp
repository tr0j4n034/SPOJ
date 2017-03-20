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
const int mod = 1000000007;

//int dp[me];
int sum[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    /*
    for(int i = 1; i < 30; i ++)
        for(int j = 1; j < 30; j ++)
            for(int k = 1; k < 30; k ++)
                dp[i + j + k] ++;
    
    int s = 0;
    for(int i = 1; i < 20; i ++){
        s += dp[i];
        cout << i << " ---> " << s << " ---> " << dp[i] << endl;
    }
     */
    for(int i = 1; i < me; i ++){
        sum[i] = (1LL * i * (i - 1) / 2 * (i - 2) / 3) % mod;
    }
    int t, x, y;
    
    scanf("%d", &t);
    while(t --){
        scanf("%d%d", &x, &y);
        printf("%d\n", (sum[y] - sum[x - 1] + mod) % mod);
    }
    
    return 0;
}
