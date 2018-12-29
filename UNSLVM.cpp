//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/29/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Totally adhoc
 */

#include <iostream>

using namespace std;

int T, N;

int main(int argc, const char * argv[]) {
    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> N;
        cout << "Case " << c + 1 << ": ";
        if (N == 1) {
            cout << 2 << endl;
        } else {
            cout << 4;
            for (int i = 0; i < N - 2; i ++) {
                cout << 9;
            }
            cout << 7 << endl;
        }
    }
    
    return 0;
}

