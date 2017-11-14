//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/14/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * M * log(N)) solution using binary search.
 */

#include <iostream>

using namespace std;

const int MAX = 3005;

int T, N, M;
int a[MAX];

int getRoot(int N) {
    int low = 0, high = 10000, middle, best = low;
    while (low <= high) {
        int middle = (low + high + 1) >> 1;
        if (middle * (middle + 1) / 2 <= N) {
            best = middle;
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }
    return best;
}

int main() {
    cin >> T;
    while (T --) {
        cin >> N >> M;
        for (int i = 0; i < M; i ++) {
            cin >> a[i];
        }
        int low = 0, high = 1 << 25, middle, best = high;
        while (low <= high) {
            middle = (low + high + 1) >> 1;
            int done = 0;
            for (int i = 0; i < M && done < N; i ++) {
                done += getRoot(middle / a[i]);
            }
            if (done >= N) {
                best = middle;
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }
        cout << best << endl;
    }
    
    return 0;
}
