//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/28/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void add(int &a, int b, int modulo) {
    a += b;
    if(a < 0) {
        a += modulo;
    }
    else if(a >= modulo) {
        a -= modulo;
    }
}

int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;
    vector<int> f(N + 1, 0);
    for(int i = 0; i < 2005; i ++) {
        if(i < 2) {
            f[i] = 1;
        }
        else if(i < 4) {
            f[i] = 0;
        }
        else {
            add(f[i], 1LL * (i + 1) * f[i - 1] % M, M);
            add(f[i], M - 1LL * (i - 2) * f[i - 2] % M, M);
            add(f[i], M - 1LL * (i - 5) * f[i - 3] % M, M);
            add(f[i], 1LL * (i - 3) * f[i - 4] % M, M);
        }
    }
    cout << f[N] << endl;
    
    return 0;
}
