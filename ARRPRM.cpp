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
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 2025;

int T, N;
int a[me], prefix_sum[me], dp[me];
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < me; i ++){
        int p = 1;
        for(int j = 2; j * j <= i && p; j ++)
            if(i % j == 0)
                p = 0;
        if(p)
            primes.push_back(i);
    }
    
    cin >> T;
    
    for(int cases = 0; cases < T; cases ++){
        cin >> N;
        for(int i = 1; i <= N; i ++)
            cin >> a[i];
        for(int i = 1; i <= N; i ++)
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
        for(int i = 1; i <= N; i ++){
            dp[i] = dp[i - 1];
            for(int j : primes){
                if(j > i)
                    break;
                dp[i] = max(dp[i], (i == j) ? prefix_sum[i] : (prefix_sum[i] - prefix_sum[i - j] + dp[i - j - 1]));
            }
        }
        
        cout << dp[N] << endl;
    }
    
    return 0;
}
