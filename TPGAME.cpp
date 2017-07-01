//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 1/07/17.
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

int T, N;
int a[me], output[me];
int lazy[me << 2];
pair<int, int> st[me << 2];

void merge(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c){
    c.first = min(a.first, b.first);
    if(b.first == c.first){
        c.second = b.second;
    }
    else{
        c.second = a.second;
    }
}
void build(int I, int low, int high){
    if(low == high){
        st[I] = make_pair(a[low], low);
        return;
    }
    int middle = (low + high) >> 1;
    build(I << 1, low, middle);
    build(I << 1 | 1, middle + 1, high);
    merge(st[I << 1], st[I << 1 | 1], st[I]);
}
void push(int I, int low, int high){
    if(lazy[I] != 0){
        st[I].first -= lazy[I];
        if(low != high){
            lazy[I << 1] += lazy[I];
            lazy[I << 1 | 1] += lazy[I];
        }
        lazy[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r, int value){
    push(I, low, high);
    if(low > r || high < l){
        return;
    }
    if(low >= l && high <= r){
        lazy[I] += value;
        push(I, low, high);
        return;
    }
    int middle = (low + high) >> 1;
    update(I << 1, low, middle, l, r, value);
    update(I << 1 | 1, middle + 1, high, l, r, value);
    merge(st[I << 1], st[I << 1 | 1], st[I]);
}
pair<int, int> get(int I, int low, int high, int l, int r){
    push(I, low, high);
    if(low > r || high < l){
        return make_pair(-1, -1);
    }
    if(low >= l && high <= r){
        return st[I];
    }
    int middle = (low + high) >> 1;
    pair<int, int> result = make_pair(0, 0);
    pair<int, int> q1 = get(I << 1, low, middle, l, r);
    pair<int, int> q2 = get(I << 1 | 1, middle + 1, high, l, r);
    merge(q1, q2, result);
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        fill(st, st + (me << 2), make_pair(0, 0));
        fill(lazy, lazy + (me << 2), 0);
        cin >> N;
        for(int i = 1; i <= N; i ++){
            cin >> a[i];
        }
        build(1, 1, N);
        for(int i = 1; i <= N; i ++){
            pair<int, int> result = get(1, 1, N, 1, N);
            output[result.second] = N + 1 - i;
            update(1, 1, N, result.second + 1, N, +1);
            update(1, 1, N, result.second, result.second, -N);
        }
        for(int i = 1; i <= N; i ++){
            cout << output[i];
            if(i < N){
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
