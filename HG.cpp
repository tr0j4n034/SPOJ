//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/25/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * sqrt(MAX_VALUE)) solution using STL map
 We just need to find the count of each possible divisors.
 The rest is multiplying those numbers and keeping the last 9 digits everytime.
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N;
int value;
map<int, int> divisors[2];

void add(int id, int value) {
    for (int i = 2; i * i <= value; i ++) {
        while (value % i == 0) {
            divisors[id][i] ++;
            value /= i;
        }
    }
    if (value > 1) {
        divisors[id][value] ++;
    }
}

int main() {
    for (int i = 0; i < 2; i ++) {
        cin >> N;
        for (int j = 0; j < N; j ++) {
            cin >> value;
            add(i, value);
        }
    }
    long long result = 1;
    int maxLength = 1;
    for (auto i : divisors[0]) {
        int _count = min(i.second, divisors[1][i.first]);
        for (int j = 0; j < _count; j ++) {
            result = result * i.first;
            maxLength = max(maxLength, (int)ceil(log10(1. * result)));
            result %= (int)1.e9;
        }
    }
    maxLength = min(maxLength, 9);
    vector<int>output;
    while (result > 0) {
        output.push_back(result % 10);
        result /= 10;
    }
    while ((int)output.size() < maxLength) {
        output.push_back(0);
    }
    reverse(output.begin(), output.end());
    for (int i : output) {
        cout << i;
    }
    cout << endl;
    return 0;
}
