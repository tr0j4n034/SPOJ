//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 9/07/17.
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

const int me = 1025;

int T;
int l[3], cnt[3];

bool safe_remove(pair<int, int> &data){
    cnt[data.second] --;
    if(cnt[0] < 1 || cnt[1] < 1 || cnt[2] < 1){
        cnt[data.second] ++;
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        vector<pair<int, int>> data;
        for(int i = 0; i < 3; i ++){
            cin >> l[i];
            cnt[i] = 0;
        }
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < l[i]; j ++){
                int x;
                cin >> x;
                data.push_back(make_pair(x, i));
            }
        }
        sort(data.begin(), data.end());
        int ptr = 0;
        int N = l[0] + l[1] + l[2];
        int result = (data.back().first - data[0].first) << 1;
        for(int i = 0; i < N; i ++){
            cnt[data[i].second] ++;
            while(safe_remove(data[ptr])){
                ptr ++;
            }
            if(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
                result = min(result, 2 * (data[i].first - data[ptr].first));
            }
        }
        cout << result << endl;
    }
    
    return 0;
}
