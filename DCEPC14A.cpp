//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 7/07/17.
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

const int me = 325;

int N, M;
int a[me][me], ft[me][me];
vector<pair<int, pair<int, int>>> data;

void add(int x, int y){
    for(int i = x; i < me; i += (i & -i)){
        for(int j = y; j < me; j += (j & -j)){
            ft[i][j] ++;
        }
    }
}
int get(int x, int y){
    int s = 0;
    for(int i = x; i > 0; i -= (i & -i)){
        for(int j = y; j > 0; j -= (j & -j)){
            s += ft[i][j];
        }
    }
    return s;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= M; j ++){
            cin >> a[i][j];
            data.push_back(make_pair(a[i][j], make_pair(i, j)));
        }
    }
    sort(data.begin(), data.end());
    int result = 0, added = 0;
    for(auto i : data){
        int x = i.second.first, y = i.second.second;
        result += added - get(x - 1, me - 1) - get(me - 1, y - 1) + get(x - 1, y - 1);
        add(i.second.first, i.second.second);
        added ++;
    }
    cout << result << endl;
    
    return 0;
}
