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

const int me = 18;

int n;
double p[me][me], dp[1 << me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> p[i][j];
    dp[(1 << n) - 1] = 1.;
    for(int i = (1 << n) - 1; i > 0; i --){
        int x = __builtin_popcount(i);
        if(x < 2)
            continue;
        for(int j = 0; j < n; j ++)
            if(i & (1 << j)){
                double wins = 0.;
                for(int k = 0; k < n; k ++)
                    if(i & (1 << k))
                        wins += p[k][j];
                dp[i ^ (1 << j)] += dp[i] * wins / (0.5 * x * (x - 1.));
            }
    }
    cout.precision(10);
    for(int i = 0; i < n; i ++){
        cout.precision(6);
        cout << fixed << dp[1 << i];
        if(i < n - 1)
            cout << " ";
    }
    cout << endl;
    
    return 0;
}
