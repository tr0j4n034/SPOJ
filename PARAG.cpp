//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 22/05/17.
//  Copyright Â© 2017 Mahmud. All rights reserved.
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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int me = 800025;
const int sz = 21;
const int mod = 1000000007;

int T, N, S;
long long M;
long long height[me];
int ft[sz][me];

int getid(vector<long long> &data, long long value){
    return int(lower_bound(data.begin(), data.end(), value) - data.begin()) + 1;
}
void add(int* ft, int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] = (ft[pos] + value) % mod;
}
int get(int* ft, int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s = (s + ft[pos]) % mod;
    return s;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    for(int _ = 0; _ < T; _ ++){
        scanf("%d%lld%d", &N, &M, &S);
        for(int i = 1; i <= N; i ++)
            scanf("%lld", &height[i]);
        vector<long long> data(height + 1, height + N + 1);
        for(int i = 1; i <= N; i ++){
            data.push_back(height[i] - M - 1);
        }
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
        for(int i = 1; i <= S; i ++)
            fill(ft[i], ft[i] + me, 0);
        reverse(height + 1, height + N + 1);
        
        for(int i = 1; i <= N; i ++){
            int pos = getid(data, height[i]);
            int nextto = getid(data, height[i] - M - 1);
            for(int j = S; j > 1; j --)
                add(ft[j], pos, get(ft[j - 1], nextto));
            add(ft[1], pos, 1);
        }
        cout << "Case " << _ + 1 << ": " << get(ft[S], me - 1) << endl;
    }
    
    return 0;
}
