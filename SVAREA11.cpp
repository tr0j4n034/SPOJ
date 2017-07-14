//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 14/07/17.
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

const int me = 10025;

int T, N, M;
int l, r;
int has[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    for(int c = 0; c < T; c ++){
        scanf("%d%d", &N, &M);
        vector<pair<int, int>> data(M);
        for(int i = 0; i < M; i ++){
            scanf("%d%d", &data[i].first, &data[i].second);
        }
        sort(data.begin(), data.end());
        fill(has, has + me, 0);
        bool good = true;
        for(int i = 0; i < M; i ++){
            N += has[data[i].first];
            if(N < 1){
                good = false;
                break;
            }
            N --;
            has[data[i].second + 1] ++;
        }
        printf("Plan %d: ", c + 1);
        if(good == true){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
    
    return 0;
}
