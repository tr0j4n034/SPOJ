//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/07/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 If a^b = c^d
  then log(a^b) = log(c^d)
  which means b * log(a) = d * log(c)
 And check the cases where a or c is equal to 1 seperately.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    long long a, b, c, d;
    
    cin >> T;
    while (T --) {
        cin >> a >> b >> c >> d;
        int r1 = 0, r2 = -1;
        if (a == 1 || b == 0) r1 = 1;
        if (c == 1 || d == 0) r2 = 1;
        if (r1 == r2 || 1. * b * log(1. * a) == 1. * d * log(1. * c)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
