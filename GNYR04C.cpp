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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 2025;
const int sz = 15;

int t, n, m;
long long dp[sz][me], sum[sz][me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n >> m;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++){
                dp[i][j] = 0;
                sum[i][j] = 0;
            }
        for(int i = 1; i <= m; i ++){
            dp[1][i] = 1;
            sum[1][i] = i;
        }
        for(int i = 2; i <= n; i ++)
            for(int j = 1; j <= m; j ++){
                dp[i][j] = sum[i - 1][j >> 1];
                sum[i][j] = sum[i][j - 1] + dp[i][j];
            }
        cout << "Data set " << c + 1 << ": " << n << " " << m << " " << sum[n][m] << endl;
    }
    
    return 0;
}
