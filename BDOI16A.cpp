//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 11/07/17.
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

const int me = 200025;
const int size = 400125;
const int offset = 200025;

int T;
int N;
int data[size];
map<int, int> positions;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> N;
        cout << "Case " << c + 1 << ":" << endl;
        
        int low = offset, high = offset;
        positions.clear();
        for(int i = 0; i < N; i ++){
            int type;
            char x;
            int y;
            cin >> type;
            if(type == 1){
                cin >> x >> y;
                if(x == 'B'){
                    data[high] = y;
                    positions[y] = high;
                    high ++;
                }
                else{
                    low --;
                    data[low] = y;
                    positions[y] = low;
                }
            }
            else if(type == 2){
                cin >> x;
                if(x == 'B'){
                    high --;
                }
                else{
                    low ++;
                }
            }
            else{
                cin >> x >> y;
                if(x == 'D'){
                    cout << data[low + y - 1] << endl;
                }
                else{
                    cout << positions[y] - low + 1 << endl;
                }
            }
        }
    }
    
    return 0;
}
