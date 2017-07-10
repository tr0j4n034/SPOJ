// I love Dolphin
// such a big prune
//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 10/07/17.
//  Copyright Â© 2017 Mahmud. All rights reserved.
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

const int me = 200025;

bitset<121> dp[me];
bitset<121> now;

void go(bitset<121> bs, int step){
    if(step > 10){
        return;
    }
    dp[step] |= bs;
    for(int i = 1; i < 121; i ++){
        if(!bs[i]){
            continue;
        }
        for(int j = 1; j <= i && i + j < 121; j ++){
            if(bs[j] && !bs[i + j]){
                bitset<121> to = bs;
                to[i + j] = 1;
                go(to, step + 1);
            }
        }
    }
}

set<int> pruners[15];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    /*
     now[1] = 1;
     go(now, 1);
     for(int i = 1; i < 11; i ++){
     cout << "in i = " << i << ": ";
     for(int j = 1; j < 121; j ++){
     if(dp[i][j] == 1){
     cout << j << ", ";
     }
     }
     cout << endl;
     }
     */
    pruners[0] = set<int>{1};
    pruners[1] = set<int>{1, 2};
    pruners[2] = set<int>{1, 2, 3, 4};
    pruners[3] = set<int>{1, 2, 3, 4, 5, 6, 8};
    pruners[4] = set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 16};
    pruners[5] = set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 24, 32};
    pruners[6] = set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 32, 33, 34, 36, 40, 48, 64};
    pruners[7] = set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52, 54, 56, 60, 64, 65, 66, 68, 72, 80, 96};
    pruners[8] = set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 72, 73, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 85, 86, 88, 90, 92, 96, 97, 98, 99, 100, 102, 104, 108, 112, 120};
    int N;
    cin >> N;
    for(int i = 0; i < 9; i ++) {
        if(pruners[i].count(N)){
            cout << i << endl;
            return 0;
        }
    }
    cout << 9 << endl;
    
    return 0;
}
