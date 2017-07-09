//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 9/07/17.
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

int N;
int l[me], r[me], ft[me];
int result[me];

void add(int pos){
    for( ; pos < me; pos += (pos & -pos)){
        ft[pos] ++;
    }
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos)){
        s += ft[pos];
    }
    return s;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i ++){
            scanf("%d%d", &l[i], &r[i]);
        }
        vector<int> values;
        for(int i = 0; i < N; i ++){
            //values.push_back(l[i]);
            values.push_back(r[i]);
        }
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        for(int i = 0; i < N; i ++){
            //l[i] = (int)(lower_bound(values.begin(), values.end(), l[i]) - values.begin()) + 1;
            r[i] = (int)(lower_bound(values.begin(), values.end(), r[i]) - values.begin()) + 1;
        }
        fill(ft, ft + me, 0);
        vector<int> ids(N);
        for(int i = 0; i < N; i ++){
            ids[i] = i;
        }
        sort(ids.begin(), ids.end(), [&](int a, int b){
            if(l[a] != l[b]){
                return l[a] < l[b];
            }
            return r[a] > r[b];
        });
        int same = 0;
        for(int i = 0; i < N; i ++){
            int id = ids[i];
            add(r[id]);
            result[id] = i - get(r[id] - 1);
            if(i > 0 && l[id] == l[ids[i - 1]] && r[id] == r[ids[i - 1]]){
                result[id] -= ++same;
            }
            else{
                same = 0;
            }
        }
        for(int i = 0; i < N; i ++){
            printf("%d", result[i]);
            if(i < N - 1){
                putchar(' ');
            }
        }
        putchar('\n');
    }
    
    return 0;
}
