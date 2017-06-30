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
const int mod = 1000000000;

int N, M;
vector<pair<int, pair<int, int>>> edges;
int parent[me], has[me];

int get(int x){
    return x == parent[x] ? x : parent[x] = get(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < M; i ++){
        int u, v, l;
        cin >> u >> v >> l;edges.push_back(make_pair(l, make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for(int i = 1; i <= N; i ++){
        parent[i] = i;
        has[i] = 1;
    }
    int result = 0, pairs = 0;
    for(auto i : edges){
        int u, v, l;
        u = i.second.first;
        v = i.second.second;
        l = i.first;
        int pu = get(u);
        int pv = get(v);
        if(pu != pv){
            pairs = (pairs + 1LL * has[pu] * has[pv] % mod) % mod;
            if(rand() & 1){
                swap(pu, pv);
            }
            parent[pu] = pv;
            has[pv] += has[pu];
        }
        result = (result + 1LL * pairs * l % mod) % mod;
    }
    cout << result << endl;
    
    return 0;
}
