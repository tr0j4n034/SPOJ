//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 13/07/17.
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

const int me = 1025;

int N, Q;
int x, y, l;
char s[2][me];
int dp[me][me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &N);
    scanf("%s", s[0]);
    scanf("%s", s[1]);
    
    for(int i = N; i > 0; i --){
        for(int j = N; j > 0; j --){
            dp[i][j] = (int)(s[0][i - 1] == s[1][j - 1]) + dp[i + 1][j + 1];
        }
    }
    scanf("%d", &Q);
    while(Q --){
        scanf("%d%d%d", &x, &y, &l);
        printf("%d\n", dp[x][y] - dp[x + l][y + l]);
    }
    
    return 0;
}
