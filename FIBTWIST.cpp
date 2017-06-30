//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 30/06/17.
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

const int me = 3025;

int T, N, M;
map<int, int> F;

int f(int N) {
    //cout << "call N = " << N << endl;
    if(F.count(N)){
        return F[N];
    }
    int k = N / 2;
    if(N % 2 == 0) { // N = 2 * k
        return F[N] = (1LL * f(k) * f(k) % M + 1LL * f(k - 1) * f(k - 1) % M) % M;
    }
    else{ // N = 2 * k + 1
        return F[N] = (1LL * f(k) * f(k + 1) % M + 1LL * f(k - 1) * f(k) % M) % M;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N >> M;
        F.clear();
        F[0] = 1;
        F[1] = 1;
        cout << (2 * (f(N + 1) - 1) % M - N % M + M) % M << endl;
    }
    
    return 0;
}
