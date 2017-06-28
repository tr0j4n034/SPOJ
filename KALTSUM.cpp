//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 28/06/17.
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
//#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 100025;
const int MAGIC = 345;

int N, Q;
int a[me];
long long prefix[me], dp[me][MAGIC];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i ++){
        scanf("%d", &a[i]);
        prefix[i] = prefix[i - 1] + a[i];
    }
    for(int j = 1; j < MAGIC && j <= N; j ++){
        for(int i = N; i > 0; i --){
            if(i + j <= N){
                dp[i][j] = -1 * dp[i + j][j];
            }
            dp[i][j] += prefix[min(i + j - 1, N)] - prefix[i - 1];
        }
    }
    while(Q --){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        if(k < MAGIC){
            int v = (((r - l + 1) / k) & 1) ? 1 : -1;
            printf("%lld\n", dp[l][k] + v * dp[r + 1][k]);
        }
        else{
            long long result = 0;
            for(int i = l, j = 1; i < r; i += k, j *= -1){
                result += (prefix[i + k - 1] - prefix[i - 1]) * j;
            }
            printf("%lld\n", result);
        }
    }
    
    return 0;
}
