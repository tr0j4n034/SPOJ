//
//  main.cpp
//  practice
//
//  Created by Mahmud on 15/07/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int T, N, d;
    string number;
    
    cin >> T;
    while (T --) {
        cin >> N >> d;
        
        vector<int> dp(1 << 10, 0xfff);
        dp[0] = 0;
        for (int i = 0; i < N; i ++) {
            cin >> number;
            int mask = 0;
            for (int i = 0; i < (int)number.size(); i ++) {
                mask |= (1 << (number[i] - '0'));
            }
            for (int j = 0; j < (1 << 10); j ++) {
                dp[j | mask] = min(dp[j | mask], dp[j] + 1);
            }
        }
        cout << (dp[(1 << 10) - 1] == 0xfff ? -1 : dp[(1 << 10) - 1]) << endl;
    }
    

    
    return 0;
}
