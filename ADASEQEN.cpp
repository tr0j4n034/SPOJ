//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/9/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 2025;

int N, M;
string a, b;
int cost[MAX], dp[MAX][MAX];

int main() {
    cin >> N >> M;
    for (int i = 'a'; i <= 'z'; i ++) {
        cin >> cost[i];
    }
    cin >> a >> b;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + cost[a[i - 1]];
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[N][M] << endl;
    
    return 0;
}
