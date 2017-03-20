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

const int me = 5025;

int T, N, K;
int a[150], dp[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N >> K;
        for(int i = 0; i < N; i ++)
            cin >> a[i];
        fill(dp + 1, dp + me, 12345);
        for(int i = 0; i < N; i ++)
            for(int j = K - a[i]; j >= 0; j --)
                dp[j + a[i]] = min(dp[j + a[i]], dp[j] + 1);
        if(dp[K] == 12345)
            cout << "impossible" << endl;
        else cout << dp[K] << endl;
    }
    
    return 0;
}
