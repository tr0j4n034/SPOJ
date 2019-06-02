//
//  main.cpp
//  practice
//
//  Created by Mahmud on 06/02/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

/*
 Simple binary search solution:
 The idea is that after sorting the starting times, do a binary search
    on the answer to the problem. To validate the given candidate greedily
    assign tasks to machines while preserving binary search condition.
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    int T, N, K;
    
    cin >> T;
    while (T --) {
        cin >> N >> K;
        
        vector<int> values(N);
        for (int i = 0; i < N; i ++) cin >> values[i];
        sort(values.begin(), values.end());
        
        int low = 0, high = 86400, middle, best = 0;
        while (low <= high) {
            middle = (low + high + 1) >> 1;
            vector<bool> used(N, false);
            for (int i = 0; i < K; i ++) {
                int lastTaken = -1;
                for (int j = 0; j < N; j ++) {
                    if (!used[j]) {
                        lastTaken = j;
                        used[j] = true;
                        break;
                    }
                }
                if (lastTaken == -1) break;
                for (int j = lastTaken + 1; j < N; j ++) {
                    if (!used[j] && values[j] - values[lastTaken] >= middle) {
                        used[j] = true;
                        lastTaken = j;
                    }
                }
            }
            bool valid = true;
            for (int i = 0; i < N && valid; i ++) valid &= used[i];
            
            if (valid) {
                best = middle;
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        cout << best << endl;
    }
    
    return 0;
}
