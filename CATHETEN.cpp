//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 19/07/17.
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

const int me = 32025;

int T, N;
int length, result;
long long M;
int p[me];
vector<int> primes;
vector<pair<int, int>> divisors;

void go(long long d, int pos){
    if(pos == length){
        long long f = M / d;
        if(f != d && (f + d) % 2 == 0){
            result ++;
        }
        return;
    }
    for(int i = 0; i <= divisors[pos].second; i ++){
        go(d, pos + 1);
        d *= divisors[pos].first;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++){
        if(!p[i]){
            primes.push_back(i);
            for(int j = i + i; j < me; j += i){
                p[j] = 1;
            }
        }
    }
    cin >> T;
    while(T --){
        cin >> N;
        M = 1LL * N * N;
        divisors.clear();
        for(int i : primes){
            if(i * i > N){
                break;
            }
            if(N % i == 0){
                int cnt = 0;
                while(N % i == 0){
                    cnt ++;
                    N /= i;
                }
                divisors.push_back(make_pair(i, 2 * cnt));
            }
        }
        if(N > 1){
            divisors.push_back(make_pair(N, 2));
        }
        length = (int)divisors.size();
        result = 0;
        go(1, 0);
        cout << result / 2 << endl;
    }
    
    return 0;
}
