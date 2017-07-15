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

const int me = 15;

int T, N;
int l[me];
double dp[1 << me];

double area(int a, int b, int c){
    double p = 0.5 * (a + b + c);
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        for(int i = 0; i < N; i ++){
            cin >> l[i];
        }
        sort(l, l + N);
        for(int i = 0; i < (1 << N); i ++){
            dp[i] = 0;
            for(int j = 0; j < N; j ++){
                if(!(i & (1 << j))){
                    continue;
                }
                for(int k = j + 1; k < N; k ++){
                    if(!(i & (1 << k))){
                        continue;
                    }
                    for(int q = k + 1; q < N; q ++){
                        if(!(i & (1 << q))){
                            continue;
                        }
                        int other = i ^ (1 << j) ^ (1 << k) ^ (1 << q);
                        if(l[j] + l[k] > l[q]){
                            dp[i] = max(dp[i], dp[other] + area(l[j], l[k], l[q]));
                        }
                    }
                }
            }
        }
        cout.precision(6);
        cout << fixed << dp[(1 << N) - 1] << endl;
    }
    
    return 0;
}
