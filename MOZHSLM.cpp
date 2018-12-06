//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/06/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Simple O(T * N) solution.
 Just consider how much each letter 'm' corresponding to the result.
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
string s;

int main() {
    cin >> T;
    while (T --) {
        cin >> s;
        int M = (int)count(s.begin(), s.end(), 's'), counter = 0;
        long long result = 0;
        for (auto ch: s) {
            if (ch == 'm') {
                result += 1LL * counter * (M - counter);
            } else if (ch == 's') {
                counter ++;
            }
        }
        cout << result << endl;
    }
    
    return 0;
}

