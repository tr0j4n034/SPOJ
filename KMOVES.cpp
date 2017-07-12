//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 12/07/17.
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

const int me = 125;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N;
    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        if(N & 1){
            puts("0");
        }
        else if(N == 0){
            puts("1");
        }
        else if(N == 2){
            puts("33");
        }
        else{
            printf("%lld\n", 7LL * N * N + 4 * N + 1);
        }
    }
    
    return 0;
}
