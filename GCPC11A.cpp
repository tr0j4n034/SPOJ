//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/27/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

long long getCount(long long N, long long K, int c) {
    long long sum = 0, power = K;
    while (1) {
        sum += N / power;
        if (power > N / K) break;
        power *= K;
    }
    return sum / c;
}

int main() {
    int t;
    long long n, k;
    
    cin >> t;
    while (t --) {
        cin >> n >> k;
        long long result = 1LL << 62;
        for (int i = 2; 1LL * i * i <= k; i ++) {
            if (k % i == 0) {
                int cnt = 0;
                while (k % i == 0) {
                    cnt ++;
                    k /= i;
                }
                result = min(result, getCount(n, i, cnt));
            }
        }
        if (k > 1) result = min(result, getCount(n, k, 1));
        
        cout << result << endl;
    }
    
    return 0;
}
