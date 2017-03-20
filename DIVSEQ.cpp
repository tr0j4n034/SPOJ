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

using namespace std;

const int me = 1025;
const int mod = 1000000009;

int N, K;
int dp[me][me];
vector<int> d[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    for(int i = 1; i <= K; i ++)
        for(int j = 1; j <= K; j ++)
            if(i % j == 0 || j % i == 0)
                d[i].push_back(j);
    for(int i = 1; i <= K; i ++)
        dp[1][i] = 1;
    for(int i = 2; i <= N; i ++)
        for(int j = 1; j <= K; j ++){
            for(int k : d[j])
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
        }
    int sum = 0;
    for(int i = 1; i <= K; i ++)
        sum = (sum + dp[N][i]) % mod;
    cout << sum << endl;
    
    return 0;
}
