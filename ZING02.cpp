//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/19/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Probably, the problem has a simpler formulation.
 You can observe the values for several ranges (brute force for small a-b pairs).
 Interestingly, the output value depends on only (b - a) difference.
 You may see the pattern by uncommenting the below lines.
 The function __builtin_clz(n) is used to find the greatest i such that 2^i <= n.
 __builtin_clzll() is simply the one for 64-bit integers.
 */

#include <iostream>
#include <cmath>

using namespace std;

//int counter = 0;
//
//void generate(int low, int high) {
//    if (low == high) {
//        counter ++;
//        return;
//    }
//    if (low + 1 == high) {
//        return;
//    }
//    int middle = (low + high) >> 1;
//    generate(low, middle);
//    generate(middle + 1, high);
//}
//
//int d[100];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    //    for (int i = 1; i < 100; i ++) {
    //        for (int j = i; j < 100; j ++) {
    //            counter = 0;
    //            generate(i, j);
    //            d[j - i] = counter;
    //            //cout << i << " " << j << " --> " << counter << endl;
    //        }
    //    }
    
    //    for (int i = 1; i < 100; i ++) {
    //        int b = 63 - __builtin_clzll(i);
    //        cout << i << " " << d[i] << endl;
    //        cout << min(i - (1LL << b) + 1, (1LL << (b + 1)) - i - 1) << endl;
    //    }
    
    int T;
    long long a, b;
    
    cin >> T;
    while (T --) {
        cin >> a >> b;
        a = b - a;
        if (a == 0) {
            cout << 1 << endl;
        } else {
            int bits = 63 - __builtin_clzll(a);
            cout << min(a - (1LL << bits) + 1, (1LL << (bits + 1)) - a - 1) << endl;
        }
    }
    
    return 0;
}

