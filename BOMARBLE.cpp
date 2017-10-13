//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/12/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100005;

int main() {
    int N;
    while (1) {
        cin >> N;
        if (N == 0) {
            break;
        }
        ++ N;
        cout << N * (3 * N - 1) / 2 << endl;
    }
    
    return 0;
}
