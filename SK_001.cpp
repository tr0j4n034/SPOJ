//
//  main.cpp
//  practice
//
//  Created by Mahmud on 06/02/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char** argv) {
    int T, N;
    
    cin >> T;
    while (T --) {
        cin >> N;
        vector<int> values(N), compressed;
        
        for (int i = 0; i < N; i ++) cin >> values[i];
        compressed = values;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        
        for (int i = 0; i < N; i ++) {
            compressed[i] = (int)(lower_bound(values.begin(), values.end(),
                                              compressed[i]) - values.begin()) + 1;
        }
        cout << accumulate(compressed.begin(),
                           compressed.end(), 0LL,
                           plus<long long>()) % 1000000007 << endl;
    }
    
    return 0;
}
