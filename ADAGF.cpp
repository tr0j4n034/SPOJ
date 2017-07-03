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

const int me = 300025;

int N;
int a[me];
map<int, int> lengths;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &N);
    for(int i = 1; i <= N; i ++){
        scanf("%d", &a[i]);
    }
    long long result = 0;
    for(int i = 1; i <= N; i ++){
        map<int, int> new_lengths;
        for(auto j : lengths){
            int to = __gcd(a[i], j.first);
            new_lengths[to] += j.second;
        }
        new_lengths[a[i]] ++;
        lengths = new_lengths;
        for(auto j : lengths){
            result += 1LL * j.first * j.second;
        }
    }
    cout << result << endl;
    
    return 0;
}
