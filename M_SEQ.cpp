//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/09/19.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

double f(int N) {
    int M = (N + 1) >> 1;
    if (N & 1) {
        return 8. * M * (4. * M * M - 1) / 3 / N / N;
    } else {
        return 8. * (2 * M + 1) * (2 * M) * (M + 1) / 3 / N / N;
    }
}
long double g(int N) {
    return sqrtl(f(N) - 1. * (N - 1.) * (N - 1.) / N / N * f(N - 1) + 1. / N / N);
}

int main(int argc, const char * argv[]) {
    int T, N;
    cin >> T;
    while (T --) {
        cin >> N;
        cout.precision(8);
        cout << fixed << g(N) << endl;
    }
    
    return 0;
}

