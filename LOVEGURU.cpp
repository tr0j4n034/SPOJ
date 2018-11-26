//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/26/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(T * N * log(N)) solution where N is maximum string length
 The problem surely has better solutions
    using some string matching algorithms and data structures...
 */

#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int T, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T >> K;
    for (int i = 0; i < T; i ++) {
        set<string> s;
        string a, b;
        cin >> a >> b;
        for (int j = 0; j < (int)a.size() - K + 1; j ++) {
            s.insert(a.substr(j, K));
        }
        bool found = false;
        for (int j = 0; j < (int)b.size() - K + 1; j ++) {
            if (s.count(b.substr(j, K))) {
                found = true;
                break;
            }
        }
        cout << (found ? "Yes" : "No") << endl;
    }
    
    return 0;
}

