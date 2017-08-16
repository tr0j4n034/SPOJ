//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/16/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1000005;

int T, N;
int c[MAX], id[MAX];

int main(int argc, const char * argv[]) {
    for (int i = 2; i * i * i < MAX; i ++) {
        int step = i * i * i;
        for (int j = step; j < MAX; j += step) {
            c[j] = 1;
        }
    }
    for (int i = 1; i < MAX; i ++) {
        id[i] = id[i - 1] + 1 - c[i];
    }
    cin >> T;
    for (int _ = 0; _ < T; _ ++) {
        cin >> N;
        cout << "Case " << _ + 1 << ": ";
        if (c[N]) {
            cout << "Not Cube Free" << endl;
        }
        else {
            cout << id[N] << endl;
        }
    }
    
    return 0;
}
