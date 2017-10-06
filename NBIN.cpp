//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/6/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 The first observation is that the number of these special numbers of length N
 is just equal to N-th Fibonacci number.
 First step is just finding the length of the output string which can be done by iterating
 till maximum length ~90.
 Then think this way: If current most digit is zero,
 can we still make N special numbers from remaining digits?
 The simulation has been done in an elegant recursive (or iterative of course) way.
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 95;

int T;
long long N;
long long f[MAX];

string generate (long long N, int length) {
    if (length < 1) {
        return "";
    }
    if (f[length + 1] >= N) {
        return "0" + generate(N, length - 1);
    }
    else {
        return "1" + generate(N - f[length + 1], length - 1);
    }
}

int main() {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i < MAX; i ++) {
        f[i] = f[i - 2] + f[i - 1];
    }
    
    cin >> T;
    while (T --) {
        cin >> N;
        int length = -1;
        for (int i = 1; i < MAX; i ++) {
            if (f[i] >= N) {
                length = i;
                break;
            }
            N -= f[i];
        }
        cout << "1" + generate(N, length - 1) << endl;
    }
    
    return 0;
}


