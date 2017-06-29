//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 29/06/17.
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
//#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 300025;
const int mod = 1000000007;

int N, Q;
int a[me];
vector<int> st[me << 2], products[me << 2];

void merge(vector<int> &a, vector<int> &b, vector<int> &c){
    int l1 = (int)a.size();
    int l2 = (int)b.size();
    int ptr1 = 0, ptr2 = 0;
    while(ptr1 < l1 && ptr2 < l2){
        if(a[ptr1] < b[ptr2]){
            c.push_back(a[ptr1 ++]);
        }
        else{
            c.push_back(b[ptr2 ++]);
        }
    }
    while(ptr1 < l1){
        c.push_back(a[ptr1 ++]);
    }
    while(ptr2 < l2){
        c.push_back(b[ptr2 ++]);
    }
}
void build_products(int id){
    int now = st[id][0];
    products[id].push_back(now);
    for(int i = 1; i < (int)st[id].size(); i ++){
        now = 1LL * now * st[id][i] % mod;
        products[id].push_back(now);
    }
}
void build(int I, int low, int high){
    if(low == high){
        st[I].push_back(a[low]);
        products[I].push_back(a[low]);
        return;
    }
    int mid = (low + high) >> 1;
    build(I << 1, low, mid);
    build(I << 1 | 1, mid + 1, high);
    merge(st[I << 1], st[I << 1 | 1], st[I]);
    build_products(I);
}
int get(int id, int h){
    if(st[id][0] > h)
        return 1;
    int pos = (int)(--upper_bound(st[id].begin(), st[id].end(), h) - st[id].begin());
    return products[id][pos];
}
int get(int I, int low, int high, int l, int r, int h){
    if(low > r || high < l){
        return 1;
    }
    if(low >= l && high <= r){
        return get(I, h);
    }
    int mid = (low + high) >> 1;
    return 1LL * get(I << 1, low, mid, l, r, h)
    * get(I << 1 | 1, mid + 1, high, l, r, h) % mod;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i ++){
        scanf("%d", &a[i]);
    }
    build(1, 1, N);
    while(Q --){
        int l, r, h;
        scanf("%d%d%d", &l, &r, &h);
        printf("%d\n", get(1, 1, N, l + 1, r + 1, h));
    }
    
    return 0;
}
