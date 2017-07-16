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

const int me = 125;

int N, M;
string a, b;
int dp[me][me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(getline(cin, a)){
        getline(cin, b);
        N = (int)a.size();
        M = (int)b.size();
        a = "$" + a;
        b = "$" + b;
        int result = 0;
        for(int i = 1; i <= N; i ++){
            for(int j = 1; j <= M; j ++){
                dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= N; i ++){
            for(int j = 1; j <= M; j ++){
                if(a[i] == b[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = max(result, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        cout << result << endl;
    }
    
    return 0;
}
