//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/26/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

int T, N;
double grade;

int main() {
    cin >> T;
    while (T --) {
        cin >> N >> grade;
        cout.precision(2);
        cout << fixed << ((N - 1) * grade + (9. - N) * 4.) / 8. << endl;
    }
    
    return 0;
}
