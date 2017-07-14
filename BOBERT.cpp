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

const int me = 100025;
const int sz = 20;

int N, M;
int a[me], l[sz], ls[1 << sz], st[2][sz][me];
int w[1 << sz];
long long dp[1 << sz];

int getMax(int l, int r){
    int d = w[r - l + 1];
    return max(st[0][d][l], st[0][d][r - (1 << d) + 1]);
}
int getMin(int l, int r){
    int d = w[r - l + 1];
    return min(st[1][d][l], st[1][d][r - (1 << d) + 1]);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < me; i ++){
        w[i] = w[i >> 1] + 1;
    }
    scanf("%d", &N);
    for(int i = 1; i <= N; i ++){
        scanf("%d", &a[i]);
        st[0][0][i] = a[i];
        st[1][0][i] = a[i];
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i ++){
        scanf("%d", &l[i]);
    }
    for(int i = 1; i < sz; i ++){
        for(int j = 1; j + (1 << i) - 1 <= N; j ++){
            st[0][i][j] = max(st[0][i - 1][j], st[0][i - 1][j + (1 << (i - 1))]);
            st[1][i][j] = min(st[1][i - 1][j], st[1][i - 1][j + (1 << (i - 1))]);
        }
    }
    for(int i = 0; i < (1 << M); i ++){
        for(int j = 0; j < M; j ++){
            if(i & (1 << j)){
                ls[i] = ls[i ^ (1 << j)] + l[j];
                break;
            }
        }
    }
    for(int i = 0; i < (1 << M); i ++){
        for(int j = 0; j < M; j ++){
            if(i & (1 << j)){
                dp[i] = max(dp[i], dp[i ^ (1 << j)]
                            + 1LL * l[j] * (getMax(ls[i] - l[j] + 1, ls[i]) - getMin(ls[i] - l[j] + 1, ls[i])));
            }
        }
    }
    printf("%lld\n", dp[(1 << M) - 1]);
    
    return 0;
}
