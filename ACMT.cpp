//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/6/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cmath>

using namespace std;

int T, A, B;

int main() {
    cin >> T;
    while (T --) {
        cin >> A >> B;
        int result = 0;
        for (int i = 0; i + i <= A && i <= B; i ++) {
            result = max(result, i + min(A - i - i, (B - i) >> 1));
        }
        cout << result << endl;
    }
    
    return 0;
}
