//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/19/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

string s;
int counts[150];

int main() {
    while (getline(cin, s)) {
        for (int i = 'a'; i <= 'z'; i ++) {
            counts[i] = 0;
        } for (char ch: s) {
            counts[ch] ++;
        }
        int odds = 0;
        for (int i = 'a'; i <= 'z'; i ++) {
            odds += (counts[i] & 1);
        }
        cout << ((odds > 1) ? -1 : 1) << endl;
    }
    
    return 0;
}

