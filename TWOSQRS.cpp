//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 29/05/17.
//  Copyright Ã�Â© 2017 Mahmud. All rights reserved.
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

using namespace std;

const int me = 100025;

int T;
long long N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        int ok = 0;
        for(int i = 1; 1LL * i * i <= N; i ++){
            long long other = N - 1LL * i * i;
            long long root = (long long)sqrt(1. * other);
            if(root * root == other){
                ok = 1;
                break;
            }
        }
        if(ok)
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
