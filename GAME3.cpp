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

const int me = 50025;

int n;
int dp[me];

int solve(int x){
    if(x == n)
        return dp[x] = 0;
    if(dp[x] != -1)
        return dp[x];
    int ans = 0;
    if(x * 2 < n)
        ans |= !solve(x * 2);
    if(x + 1 < n)
        ans |= !solve(x + 1);
    return dp[x] = ans;
}

const long long INF = 1000000000000000LL;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 3; i < 1000; i += 2){
        int f = 0;
        for(int j = 2; j < 20; j += 2)
            if(i & (1LL << j)){
                f = 1;
                break;
            }
        //if(!f)
          //  cout << i << endl;
    }
    /// found using oeis
    /// https://oeis.org/search?q=3%2C+9%2C+11%2C+33%2C+35%2C+41&language=english&go=Search
    
    int t;
    long long n;
    
    cin >> t;
    while(t --){
        cin >> n;
        int f = !(n & 1);
        for(int i = 2; i < 50; i += 2)
            if(n & (1LL << i)){
                f = 1;
                break;
            }
        if(f == 0)
            cout << "Ivica" << endl;
        else cout << "Marica" << endl;
    }
    
    return 0;
}
