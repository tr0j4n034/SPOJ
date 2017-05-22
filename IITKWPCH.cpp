//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 22/05/17.
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

const int me = 1025;

int T, N;
char ch;
long long x;
int cnt[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);

    while(T --){
        scanf("%d", &N);
        for(int i = 0; i < me; i ++)
            cnt[i] = 0;
        for(int i = 0; i < N; i ++){
            scanf("%lld", &x);
            int mask = 0;
            while(x > 0){
                mask |= 1 << (x % 10);
                x /= 10;
            }
            cnt[mask] ++;
        }
        long long result = 0;
        for(int i = 0; i < me; i ++){
            result += 1LL * cnt[i] * (cnt[i] - 1) / 2;
            for(int j = i + 1; j < me; j ++)
                if(i & j)
                    result += 1LL * cnt[i] * cnt[j];
        }
        cout << result << endl;
    }
    
    return 0;
}
