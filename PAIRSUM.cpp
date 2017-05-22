//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 20/05/17.
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
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int me = 1000025;

int N, Q;
int l, r;
int a[me];
long long sum[me], square_sum[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i ++)
        cin >> a[i];
    for(int i = 1; i <= N; i ++){
        sum[i] = sum[i - 1] + a[i];
        square_sum[i] = square_sum[i - 1] + 1LL * a[i] * a[i];
    }
    cin >> Q;
    while(Q --){
        cin >> l >> r;
        ++l, ++r;
        cout << ((sum[r] - sum[l - 1]) * (sum[r] - sum[l - 1]) + square_sum[r] - square_sum[l - 1]) / 2 << endl;
    }
    
    return 0;
}
