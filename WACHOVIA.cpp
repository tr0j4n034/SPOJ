#include<iostream>
#include <list>
#include <stack>
#include <vector>
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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1025;

int t, n, s, a, b;
int dp[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> s >> n;
        for(int i = 1; i <= s; i ++)
            dp[i] = -1;
        for(int i = 1; i <= n; i ++){
            cin >> a >> b;
            for(int j = s - a; j >= 0; j --)
                if(dp[j] != -1)
                    dp[j + a] = max(dp[j + a], dp[j] + b);
        }
        int ans = 0;
        for(int i = 1; i <= s; i ++)
            ans = max(ans, dp[i]);
        cout << "Hey stupid robber, you can get " << ans << "." << endl;
    }
    
    return 0;
}

