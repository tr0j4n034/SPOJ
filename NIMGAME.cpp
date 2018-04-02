//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/01/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

int fib[30];

int main() {
    fib[0] = 1;
    fib[1] = 1;
    
    for (int i = 2; i < 30; i ++) {
        fib[i] = fib[i - 2] + fib[i - 1];
        if (fib[i] > 2000) break;
        cout << fib[i] << endl;
    }
    
    return 0;
}
