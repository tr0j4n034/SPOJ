//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 30/06/17.
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

const int me = 100025;

int N;
int dp[me][2];
vector<int> v[me];

void dfs(int node, int parent){
    int included = 1;
    int not_included = 0;
    for(int i : v[node]){
        if(i == parent){
            continue;
        }
        dfs(i, node);
        included += min(dp[i][0], dp[i][1]);
        not_included += dp[i][0];
    }
    dp[node][0] = included;
    dp[node][1] = not_included;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i < N; i ++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int root = -1;
    for(int i = 1; i <= N; i ++){
        if((int)v[i].size() == 1){
            root = i;
            break;
        }
    }
    dfs(root, -1);
    cout << min(dp[root][0], dp[root][1]) << endl;
    
    return 0;
}
