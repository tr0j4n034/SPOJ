//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/09/19.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(N * log(N)) solution via Fenwick tree
 The main idea is that if we are keeping the original
    elements at positions i and j, then there should be enough gap
 to place between these elements: data[j] - data[i] >= j - i
 Or data[j] - j >= data[i] - i.
 Therefore, subtract index value from each element where it will stay positive
    and calculate LIS of the new list.
 The answer is N - LIS.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1 << 20;

int N;
int data[MAX_SIZE];
int ftree[MAX_SIZE];

void add(int position, int value) {
    for ( ; position <= N; position += (position & -position)) {
        ftree[position] = max(ftree[position], value);
    }
}
int get(int position) {
    int best = 0;
    for ( ; position > 0; position -= (position & -position)) {
        best = max(best, ftree[position]);
    }
    return best;
}

int main(int argc, const char * argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) scanf("%d", &data[i]);
    vector<int> fits;
    for (int i = 1; i <= N; i ++) {
        if (data[i] >= i) fits.push_back(data[i] - i);
    }
    vector<int> values = fits;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int &i: fits) {
        i = (int)(lower_bound(values.begin(), values.end(), i) - values.begin()) + 1;
    }
    int lis = 0;
    for (int i: fits) {
        int currentLis = get(i) + 1;
        lis = max(lis, currentLis);
        add(i, currentLis);
    }
    cout << N - lis << endl;
    return 0;
}

