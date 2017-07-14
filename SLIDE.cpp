//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 14/07/17.
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
const int sz = 10;

int N, M;
int grid[me][sz], dp[me][sz][sz];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            cin >> grid[i][j];
        }
    }
    dp[0][0][M - 1] = grid[0][0] + grid[0][M - 1];
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            for(int k = 0; k < M; k ++){
                if(dp[i][j][k] == 0){
                    continue;
                }
                for(int q = -1; q < 2; q ++){
                    if(j + q > -1 && j + q < M){
                        for(int l = -1; l < 2; l ++){
                            if(k + l > -1 && k + l < M){
                                dp[i + 1][j + q][k + l] = max(dp[i + 1][j + q][k + l],
                                                              dp[i][j][k] + grid[i + 1][j + q]
                                                              + (j + q == k + l ? 0 : grid[i + 1][k + l]));
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[N - 1][0][M - 1] << endl;
    
    return 0;
}
