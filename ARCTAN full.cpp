//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/27/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 As problem requires the solution in only 256 bytes, you may refer to the accepted code as well.
 This is a short outline of the solution, which would get accepted if there is no source code limit...
 O(T * MAX) solution, where MAX = 60000
 As we know arctan(a) + arctan(b) = arctan((a + b) / (1 - a * b))
 For our problem:
 arctan(1 / a) = arctan(1 / b) + arctan(1 / c)
 1 / a = (1 / b + 1 / c) / (1 - (1 / a) * (1 / b)) =
 = ... = (b + c) / (b * c - 1)
 So we get: a = (b * c - 1) / (b + c)
 Now let b = a + k, c = a + q
 a = ((a + k) * (a + q) - 1) / (a + k + a + q)
 By simplifying the last equation:
 a * a + 1 = k * q
 Of course, for the min(b + c) = min(a + k + a + q) = a * 2 + min(k + q)
 So we need to find the nearest divisor of (a * a + 1) to its square root sqrt(a * a + 1)
 */

#include <iostream>
#include <cmath>

using namespace std;

int T, N;

int main() {
    cin >> T;
    while (T --) {
        cin >> N;
        long long top = 1LL * N * N + 1;
        long long root = (int)(1. * top);
        while (top % root) root --;
        cout << N + N + top / root + root << endl;
    }
    
    return 0;
}
