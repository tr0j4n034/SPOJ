//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/01/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

int f(int a, int b, int k) {
    int s = 0;
    for (int i = a; i <= b; i ++) {
        int j = i, cnt = 0;
        while (j > 0) {
            cnt += j % 2;
            j /= 2;
        }
        if (cnt == k) s ++;
    }
    return s;
}

int c[35][35];

int get(int a, int k) {
    int ones = 0, result = 0;
    for (int i = 30; i >= 0; i --) {
        if (ones > k) break;
        if (ones == k) {
            result ++;
            break;
        }
        if ((a >> i) & 1) {
            result += c[i][k - ones];
            ones ++;
        }
    }
    return result;
}

int a, b, k;

int main() {
    for (int i = 0; i < 35; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    cin >> a >> b >> k;
    cout << f(a, b, k) << endl;
    cout << get(b, k) - get(a - 1, k) << endl;
    
    return 0;
}
