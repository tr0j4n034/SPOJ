//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/24/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 10005;

int T;
int l, k;
int can[MAX], root[MAX];

int main() {
    for (int i = 1; i < MAX; i ++) root[i] = (int)sqrt(i);
    
    cin >> T;
    for (int i = 0; i < T; i ++) {
        cin >> l >> k;
        int sum = l * (l + 1) / 2;
        for (int j = 1; j <= l; j ++) can[j] = 1;
        for (int j = l; j > 0 && k > 0; j --) {
            int take = min(can[j], k);
            k -= take;
            can[root[j]] += take;
            sum = sum - take * (j - root[j]);
        }
        cout << sum << endl;
    }
    
    return 0;
}
