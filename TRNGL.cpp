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

const int me = 2025;
const int mod = 100007;

int T, N;
int c[me][me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < me; i ++){
        for(int j = 0; j <= i; j ++){
            if(j == 0){
                c[i][j] = 1;
            }
            else{
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
    }
    cin >> T;
    while(T --){
        cin >> N;
        N -= 2;
        cout << (c[2 * N][N] - c[2 * N][N + 1] + mod) % mod << endl;
    }
    
    return 0;
}
