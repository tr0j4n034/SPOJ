//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 16/07/17.
//  Copyright © 2017 Mahmud. All rights reserved.
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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 10025;
const long long offset = 1LL << 55;

int T, N;
int a[me][2];
long long dp[me][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        for(int i = 1; i <= N; i ++){
            cin >> a[i][0];
        }
        for(int i = 1; i <= N; i ++){
            cin >> a[i][1];
        }
        long long result = -offset;
        for(int w = 0; w < 2; w ++){
            for(int i = 1; i <= N; i ++){
                dp[i][0] = dp[i][1] = -offset;
            }
            dp[1][w] = (w == 1 ? -1 : 1) * a[1][w];
            for(int i = 2; i <= N; i ++){
                if(dp[i - 1][0] != -offset){
                    dp[i][1] = max(dp[i][1], dp[i - 1][0] - a[i][1]);
                }
                if(dp[i - 1][1] != -offset){
                    dp[i][0] = max(dp[i][0], dp[i - 1][1] + a[i][0]);
                    dp[i][1] = max(dp[i][1], dp[i - 1][1] - a[i][1]);
                }
            }
            if(w == 0){
                result = max(result, dp[N][1]);
            }
            else{
                result = max(result, dp[N][0]);
                result = max(result, dp[N][1]);
            }
        }
        cout << result << endl;
    }
    
    return 0;
}
