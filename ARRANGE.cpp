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

int T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        vector<int> data;
        int one = 0, two = 0, three = 0;
        for(int i = 0; i < N; i ++){
            int x;
            cin >> x;
            if(x == 1)
                one ++;
            else if(x == 2)
                two ++;
            else if(x == 3)
                three ++;
            else data.push_back(x);
        }
        sort(data.begin(), data.end());
        reverse(data.begin(), data.end());
        vector<int> output;
        for(int _ = 0; _ < one; _ ++)
            output.push_back(1);
        if(two + three == 2 && 2 + one == N){
            output.push_back(2);
            output.push_back(3);
        }
        else{
            for(auto i : data)
                output.push_back(i);
            if(three)
                output.push_back(3);
            if(two)
                output.push_back(2);
        }
        for(int i = 0; i < N; i ++){
            cout << output[i];
            if(i < N - 1)
                cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
