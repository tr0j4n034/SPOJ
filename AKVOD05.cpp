//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 15/07/17.
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

int T, N, K;
int a[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N >> K;
        for(int i = 1; i <= K; i ++){
            cin >> a[i];
        }
        N -= K;
        N %= (K + 1);
        if(N == 0){
            N = K + 1;
        }
        N += K;
        set<int> notactive;
        map<int, int> counts;
        for(int i = 0; i < me; i ++){
            notactive.insert(i);
        }
        for(int i = 1; i <= K; i ++){
            if(notactive.count(a[i])){
                notactive.erase(a[i]);
            }
            counts[a[i]] ++;
        }
        for(int i = K + 1; i <= N; i ++){
            a[i] = *notactive.begin();
            counts[a[i - K]] --;
            if(counts[a[i - K]] == 0){
                notactive.insert(a[i - K]);
            }
            counts[a[i]] ++;
            if(notactive.count(a[i])){
                notactive.erase(a[i]);
            }
        }
        cout << a[N] << endl;
    }
    
    return 0;
}
