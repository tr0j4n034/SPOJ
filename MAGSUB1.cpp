//
//  main.cpp
//  practice
//
//  Created by Mahmud on 14/07/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    vector<int> primes = vector<int>{2, 3, 5, 7, 11, 13, 17, 19, 23};
    int T, N;
    string text;
    
    cin >> T;
    while (T --) {
        cin >> N;
        cin >> text;
        
        int impPtr = 0;
        long long result = 0;
        for (int i = 0; i < N; i ++) {
            while (impPtr < i ||
                   (impPtr < N && find(primes.begin(), primes.end(), text[impPtr] - 'A' + 1) == primes.end()))
                impPtr ++;
            if (impPtr < N)
                result += N - impPtr;
        }
        cout << result << endl;
    }
    
    return 0;
}
