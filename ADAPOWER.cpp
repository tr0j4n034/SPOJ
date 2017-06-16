//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 16/06/17.
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

const int DOLPHIN = 2809;
const int me = 225;

int N, Q;
int a[me][me], b[me][me], c[me][me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    srand((unsigned)time(NULL));
    
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++){
            scanf("%d", &a[i][j]);
        }
    }
    while(Q --){
        int type;
        scanf("%d", &type);
        if(type == 1){
            int x, y, X, Y, value;
            scanf("%d%d%d%d%d", &x, &y, &X, &Y, &value);
            for(int i = x + 1; i <= X + 1; i ++){
                for(int j = y + 1; j <= Y + 1; j ++){
                    a[i][j] += value;
                }
            }
        }
        else{
            for(int i = 1; i <= N; i ++){
                for(int j = 1; j <= N; j ++){
                    scanf("%d", &b[i][j]);
                }
            }
            bool same = true;
            for(int i = 1; i <= N; i ++){
                for(int j = 1; j <= N; j ++){
                    c[i][j] = 0;
                }
            }
            for(int i = 1; i <= N && same; i ++){
                for(int j = 1; j <= N && same; j ++){
                    for(int k = 1; k <= N && same; k ++){
                        c[i][j] += a[i][k] * a[k][j];
                        if(c[i][j] > b[i][j]){
                            same = false;
                            break;
                        }
                    }
                }
            }
            for(int i = 1; i <= N; i ++){
                for(int j = 1; j <= N; j ++){
                    if(b[i][j] != c[i][j]){
                        same = false;
                        break;
                    }
                }
            }
            if(same){
                puts("yes");
            }
            else{
                puts("no");
            }
        }
    }
    
    return 0;
}
