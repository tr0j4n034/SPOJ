//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/23/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <bitset>

using namespace std;

const int S = 5005;
const int OFFSET = 100000;
const int MAX_SUM = 600001;

int N;
int a[S];
bitset<MAX_SUM> bs[3][S];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        cin >> a[i];
        a[i] += OFFSET;
    }
    for (int i = 1; i < N; i ++) {
        bs[0][i + 1] = bs[0][i];
        bs[0][i + 1][a[i]] = 1;
    }
    for (int i = 1; i < N; i ++) {
        bs[1][i + 1] = bs[1][i];
        bs[1][i + 1] |= (bs[0][i] << a[i]);
        bs[1][i + 1][a[i] + a[i]] = 1;
    }
    for (int i = 1; i < N; i ++) {
        bs[2][i + 1] = bs[2][i];
        bs[2][i + 1] |= (bs[1][i] << a[i]);
        bs[2][i + 1] |= (bs[0][i] << (a[i] << 1));
        bs[2][i + 1][a[i] + a[i] + a[i]] = 1;
    }
    int result = 0;
    for (int i = 1; i <= N; i ++) {
        if (bs[2][i][a[i] + 2 * OFFSET]) {
            result ++;
        }
    }
    cout << result << endl;
    
    return 0;
}
