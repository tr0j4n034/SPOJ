//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 10/06/17.
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

const int me = 50025;

template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int N, Q;
int last_ans = 0;
int l, r, k;
int a[me];
vector<int> st[me << 2];

void merge(vector<int> &a, vector<int> &b, vector<int> &to){
    int p1 = 0, p2 = 0;
    int l1 = (int)a.size(), l2 = (int)b.size();
    while(p1 < l1 && p2 < l2){
        if(a[p1] < b[p2])
            to.push_back(a[p1 ++]);
        else to.push_back(b[p2 ++]);
    }
    while(p1 < l1){
        to.push_back(a[p1 ++]);
    }
    while(p2 < l2){
        to.push_back(b[p2 ++]);
    }
}
void build(int I, int low, int high){
    if(low == high){
        st[I].push_back(a[low]);
        return;
    }
    int middle = (low + high) >> 1;
    build(I << 1, low, middle);
    build(I << 1 | 1, middle + 1, high);
    merge(st[I << 1], st[I << 1 | 1], st[I]);
}
int get(int I, int low, int high, int l, int r, int k){
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r){
        return (int)(st[I].end() - upper_bound(st[I].begin(), st[I].end(), k));
    }
    int middle = (low + high) >> 1;
    return get(I << 1, low, middle, l, r, k)
    + get(I << 1 | 1, middle + 1, high, l, r, k);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    //scanf("%d", &N);
    fastInput(N);
    for(int i = 1; i <= N; i ++){
        //scanf("%d", &a[i]);
        fastInput(a[i]);
    }
    build(1, 1, N);
    //scanf("%d", &Q);
    fastInput(Q);
    while(Q --){
        int A, B, C;
        //scanf("%d%d%d", &A, &B, &C);
        fastInput(A);
        fastInput(B);
        fastInput(C);
        l = A ^ last_ans;
        r = B ^ last_ans;
        k = C ^ last_ans;
        if(l < 1)
            l = 1;
        if(r > N)
            r = N;
        if(l > r){
            printf("%d\n", last_ans = 0);
        }
        else{
            printf("%d\n", last_ans = get(1, 1, N, l, r, k));
        }
    }
    
    return 0;
}

