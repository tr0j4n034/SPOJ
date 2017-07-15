//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 16/07/17.
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
int a[me];
int prefix[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> N >> M;
        for(int i = 1; i <= N; i ++){
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }
        int result = N + 1;
        if(M == 0){
            result = 0;
            goto print;
        }
        for(int i = 1; i <= N; i ++){
            int low = i, high = N, middle, best = N + 1;
            while(low <= high){
                middle = (low + high + 1) >> 1;
                if(prefix[middle] - prefix[i - 1] >= M){
                    best = middle;
                    high = middle - 1;
                }
                else{
                    low = middle + 1;
                }
            }
            if(best != N + 1){
                result = min(result, best - i + 1);
            }
        }
        if(result == N + 1){
            result = -1;
        }
        print:cout << "Case " << c + 1 << ": " << result << endl;
    }
    
    return 0;
}
