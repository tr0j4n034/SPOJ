//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/12/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 O(N * log(N)) solution with Fenwick tree
 Input values are compressed for Eenwick tree processing
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 500025;

int N, M, P;
int data[MAX], ftree[MAX];

void add (int pos, int value) {
    for ( ; pos <= M; pos += (pos & -pos)) {
        ftree[pos] += value;
    }
}
int get (int pos) {
    int s = 0;
    for ( ; pos > 0; pos -= (pos & -pos)) {
        s += ftree[pos];
    }
    return s;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &P);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &data[i]);
    }
    vector<int> values = vector<int>(data + 1, data + N + 1);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 1; i <= N; i ++) {
        data[i] = (int)(lower_bound(values.begin(), values.end(), data[i]) - values.begin()) + 1;
    }
    M = (int)values.size();
    int id = -1;
    long long inversionCount = 0, best = -1;
    for (int i = 1; i <= N; i ++) {
        if (i > P) {
            add(data[i - P], -1);
            inversionCount -= get(data[i - P] - 1);
        }
        add(data[i], 1);
        inversionCount += min(i, P) - get(data[i]);
        if (inversionCount > best) {
            best = inversionCount;
            id = i - P + 1;
        }
    }
    printf("%d %lld\n", id, best);
    
    return 0;
}
