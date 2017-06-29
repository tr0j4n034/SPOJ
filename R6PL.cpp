//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 29/06/17.
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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 100025;
const int offset = 50005;

int T, N;
int x, y;
int dp[me], temp[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        fill(dp, dp + me, 0);
        fill(temp, temp + me, 0);
        dp[offset] = 1;
        for(int i = 0; i < N; i ++){
            cin >> x >> y;
            fill(temp, temp + me, 0);
            for(int j = 0; j < me; j ++){
                if(dp[j]){
                    temp[j + x - y] = 1;
                    temp[j + y - x] = 1;
                }
            }
            copy(temp, temp + me, dp);
        }
        int best = me;
        for(int i = 0; i < me; i ++){
            if(dp[i] != 0 && abs(i - offset) < abs(best - offset)){
                best = i;
            }
        }
        cout << abs(best - offset) << endl;
    }
    
    return 0;
}
