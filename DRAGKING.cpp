//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/27/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int T;
string s;
int dp[N][N];

int main() {
    cin >> T;
    while (T --) {
        cin >> s;
        int l = (int)s.length();
        long long sum = 0;
        for (int i = 1; i <= l; i ++) {
            for (int j = 0; j + i - 1 < l; j ++) {
                dp[j][j + i - 1] = (s[j] == s[j + i - 1]) && (i > 2 ? dp[j + 1][j + i - 2] : 1);
                if (dp[j][j + i - 1]) sum += i * i * i;
            }
        }
        cout << sum << endl;
    }
    
    return 0;
}

