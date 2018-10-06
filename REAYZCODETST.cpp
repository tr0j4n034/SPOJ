//
//  main.cpp
//  practice
//
//  Created by Mahmud on 06/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, X;

int main() {

    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> N >> X;
        vector<int> data(N);
        for (int i = 0; i < N; i ++) {
            cin >> data[i];
        } sort(data.begin(), data.end());
        long long result = 0;
        int ptrLow = 0, ptrHigh = 0;
        for (int i = 0; i < N; i ++) {
            while (ptrLow < N && data[ptrLow] < data[i] + X) ptrLow ++;
            while (ptrHigh < N && data[ptrHigh] <= data[i] + X) ptrHigh ++;
            result += ptrHigh - ptrLow;
        }
        cout << "Case " << c + 1 << ": " << result - N * int(X == 0) << endl;
    }
    
    return 0;
}
