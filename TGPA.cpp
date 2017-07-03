//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 3/07/17.
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

const int me = 200025;
const int mod = 1000000007;

int T, N;
int fac[me], ft[me];

void add(int pos){
    for( ; pos < me; pos += (pos & -pos)){
        ft[pos] += 1;
    }
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos)){
        s += ft[pos];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    fac[0] = 1;
    for(int i = 1; i < me; i ++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    cin >> T;
    while(T --){
        cin >> N;
        int result = 1;
        fill(ft, ft + me, 0);
        for(int i = 1; i <= N; i ++){
            int x;
            cin >> x;
            int smaller = x - 1 - get(x);
            add(x);
            result = (result + 1LL * smaller * fac[N - i] % mod) % mod;
        }
        cout << result << endl;
    }
    
    return 0;
}
