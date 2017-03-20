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

const int me = 1000025;

int dp[me];

int solve(int N){
    if(N < 1)
        return 0;
    if(dp[N] != -1)
        return dp[N];
    int s = 0;
    if(N > 0 && !solve(N - 1))
        s = 1;
    if(N > 1 && !solve(N - 2))
        s = 1;
    if(N > 4 && !solve(N - 5))
        s = 1;
    return dp[N] = s;
}

int T;
long long N;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    
    //for(int i = 0; i < 20000; i ++)
    //     dp[i] = -1;
    //for(int i = 0; i < 20000; i ++)
    //     cout << i << " --> " << solve(i) << endl;
    //for(int i = 0; i < 20000; i ++){
    //    if(i % 3 == 0 && dp[i] == 1)
    //        assert(false);
    //    if(i % 3 != 0 && dp[i] == 0)
    //        assert(false);
    //}
    
    cin >> T;
    while(T --){
        cin >> N;
        if(N % 3 == 0)
            cout << "Ragini" << endl;
        else cout << "Hemlata" << endl;
    }
    
    return 0;
}