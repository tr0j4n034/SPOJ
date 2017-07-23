//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 23/07/17.
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
const int mod = 100000007;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    int T, N;
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> N;
        int sum = 0;
        for(int i = 0; i < N; i ++){
            int x;
            cin >> x;
            sum = (sum + x) % mod;
        }
        int pw = 1;
        for(int i = 1; i < N; i ++){
            pw = pw * 2 % mod;
        }
        cout << "Case " << c + 1 << ": " << 1LL * sum * pw % mod << endl;
    }
    
    return 0;
}
