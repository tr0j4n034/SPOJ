//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 13/07/17.
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

const int me = 2025;
const int offset = 1005;

int T, N;
int x[me], y[me];
int was[me][me];

bool collinear(int a, int b){
    return x[a] * y[b] == y[a] * x[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        for(int i = 0; i < me; i ++){
            for(int j = 0; j < me; j ++){
                was[i][j] = 0;
            }
        }
        cin >> N;
        for(int i = 0; i < N; i ++){
            cin >> x[i] >> y[i];
            was[x[i] + offset][y[i] + offset] = 1;
        }
        bool found = false;
        for(int i = 0; i < N && !found; i ++){
            for(int j = i + 1; j < N && !found; j ++){
                if(x[i] == 0 && y[i] == 0){
                    continue;
                }
                if(y[i] == 0 && y[j] == 0){
                    continue;
                }
                if(collinear(i, j)){
                    continue;
                }
                if(x[i] + x[j] > -offset && x[i] + x[j] + offset < me){
                    if(y[i] + y[j] > -offset && y[i] + y[j] + offset < me){
                        if(was[x[i] + x[j] + offset][y[i] + y[j] + offset]){
                            found = true;
                        }
                    }
                }
                
            }
        }
        if(!found){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
