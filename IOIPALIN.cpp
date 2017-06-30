//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 30/06/17.
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

const int me = 5025;

int N;
string a, b;
int dp[me][me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    a = "$" + a;
    b = "$" + b;
    
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    cout << N - dp[N][N] << endl;
    
    return 0;
}
