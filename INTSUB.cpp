//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 11/07/17.
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

const int me = 2025;
const int mod = 1000000007;

int T, N;
int pw[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    pw[0] = 1;
    for(int i = 1; i < me; i ++){
        pw[i] = pw[i - 1] * 2 % mod;
    }
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> N;
        int result = pw[N * 2] - 1;
        for(int i = 1; i <= N * 2; i ++){
            int good = 0;
            for(int j = i + 1; j <= N * 2; j ++){
                if(j % i != 0){
                    good ++;
                }
            }
            result = (result + mod - pw[good]) % mod;
        }
        cout << "Case " << c + 1 << ": " << result << endl;
    }
    
    return 0;
}
