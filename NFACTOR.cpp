//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 12/05/17.
//  Copyright Â© 2017 Mahmud. All rights reserved.
//

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
#include <unordered_set>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 1000025;
const int sz = 11;

int dp[sz][me], has[me], primes[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!primes[i])
            for(int j = i; j < me; j += i)
                has[j] ++, primes[j] = 1;
    for(int i = 1; i < me; i ++)
        dp[has[i]][i] = 1;
    for(int i = 0; i < sz; i ++)
        for(int j = 1; j < me; j ++)
            dp[i][j] += dp[i][j - 1];
    
    int t, n, a, b;
    cin >> t;
    while(t --){
        cin >> a >> b >> n;
        cout << dp[n][b] - dp[n][a - 1] << endl;
    }
    
    return 0;
}
