//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/09/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Solution using binary search + generation of all possibilities
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, M;

void getCount(long long product, long long N, int p, vector<int> &data, int &skipped) {
    if (p >= (int)data.size()) {
        skipped ++;
        return;
    } else if (product > N) {
        return;
    }
    for (int i = 0; ; i ++) {
        if (product <= N) {
            getCount(product, N, p + 1, data, skipped);
        } else {
            break;
        }
        product *= data[p];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        } vector<int> data(N);
        for (int i = 0; i < N; i ++) {
            cin >> data[i];
        }
        sort(data.begin(), data.end(), greater<int>());
        long long low = 2, high = 1LL << 40, middle, best = high;
        while (low <= high) {
            middle = (low + high + 1) >> 1;
            int ways = 0;
            getCount(1, middle, 0, data, ways);
            if (ways >= M + 1) {
                best = middle;
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
        cout << best << endl;
    }
    
    //cout << "clock = " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
