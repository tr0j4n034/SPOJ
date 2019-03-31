//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/31/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char* argv[]) {
    int N, best = -0xabcde, sum = 0;
    
    cin >> N;
    for (int i = 0; i < N; i ++) {
        int x; cin >> x;
        sum = max(sum + x, x);
        best = max(best, sum);
    }
    cout << best << endl;
    
    return 0;
}

