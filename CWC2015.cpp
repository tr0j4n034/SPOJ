//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 23/07/17.
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

const int me = 1000025;

int T, N;
int a[45];
bitset<25> bs[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int c = 0; c < T; c ++){
        cout << "Case " << c + 1 << ": ";
        cin >> N;
        int total_sum = 0;
        for(int i = 0; i < N; i ++){
            cin >> a[i];
            total_sum += a[i];
        }
        if(total_sum & 1){
            cout << "No" << endl;
            continue;
        }
        if(N & 1){
            cout << "No" << endl;
            continue;
        }
        int half = total_sum >> 1;
        for(int i = 0; i <= half; i ++){
            bs[i].reset();
        }
        for(int i = 0; i < N; i ++){
            for(int j = half; j > a[i]; j --){
                bs[j] |= bs[j - a[i]] << 1;
            }
            bs[a[i]][1] = 1;
        }
        cout << (bs[half][N >> 1] ? "Yes" : "No") << endl;
    }
    
    return 0;
}
