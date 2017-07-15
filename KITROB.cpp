//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 15/07/17.
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

const int me = 25;

int t, w, l, n;
int x[me], y[me];
double dis[me][me], ex[me];
double dp[1 << 19][19];

double d(int X, int Y, int x, int y){
    return sqrt(1. * (X - x) * (X - x) + 1. * (Y - y) * (Y - y));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> w >> l;
        cin >> n;
        ++ n;
        for(int i = 1 ; i < n ; i ++)
            cin >> x[i] >> y[i];
        cin >> x[0] >> y[0];
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < n ; j ++){
                dis[i][j] = d(x[i], y[i], w + w - x[j], y[j]);
                dis[i][j] = min(dis[i][j], d(x[i], y[i], -x[j], y[j]));
                dis[i][j] = min(dis[i][j], d(x[i], y[i], x[j], l + l - y[j]));
                dis[i][j] = min(dis[i][j], d(x[i], y[i], x[j], -y[j]));
                //dis[j][i] = dis[i][j];
            }
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < n ; j ++)
                assert(dis[i][j] == dis[j][i]);
        for(int i = 1 ; i < n ; i ++)
            cerr << dis[0][i] << endl;
        for(int i = 0 ; i < n ; i ++){
            ex[i] = min(1. * x[i], 1. * w - 1. * x[i]);
            ex[i] = min(ex[i], 1. * y[i]);
            ex[i] = min(ex[i], 1. * l - 1. * y[i]);
        }
        for(int i = 0 ; i < (1 << n) ; i ++)
            for(int j = 0 ; j < n ; j ++)
                dp[i][j] = 1.e9 - 1;
        for(int i = 1 ; i < n ; i ++)
            dp[1 << i][i] = d(x[0], y[0], x[i], y[i]);
        dp[0][0] = 0;
        for(int i = 1 ; i < (1 << n) ; i ++)
            for(int j = 1 ; j < n ; j ++)
                if(i & (1 << j)){
                    int other = i ^ (1 << j);
                    for(int k = 1 ; k < n ; k ++)
                        if(other & (1 << k))
                            dp[i][j] = min(dp[i][j], dp[other][k] + dis[k][j]);
                }
        double result = 1.e9;
        cout.precision(10);
        for(int i = 1 ; i < n ; i ++)
            result = min(result, dp[((1 << n) - 1) ^ 1][i] + ex[i]);
        cout << fixed << result << endl;
    }
    
    return 0;
}
