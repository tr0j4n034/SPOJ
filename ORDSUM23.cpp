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

const int me = 1000025;
const int mod = 1000000007;

int T, N;
int dp[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i < me; i ++){
        dp[i] = dp[i - 2] + dp[i - 3];
        if(dp[i] >= mod)
            dp[i] -= mod;
    }
    
    cin >> T;
    while(T --){
        cin >> N;
        cout << dp[N] << endl;
    }
    
    return 0;
}
