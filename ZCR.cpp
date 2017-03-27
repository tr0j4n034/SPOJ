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

int T, N, K;
double p;
double dp[me][me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N >> K;
        for(int i = 1; i <= N; i ++)
            for(int j = 0; j <= i; j ++)
                dp[i][j] = 0;
        dp[0][0] = 1.;
        for(int i = 1; i <= N; i ++){
            cin >> p;
            dp[i][0] = dp[i - 1][0] * (1 - p);
            for(int j = 1; j <= i; j ++){
                dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j] * (1 - p);
            }
        }
        cout.precision(10);
        cout << fixed << dp[N][K] << endl;
    }
    
    return 0;
}
