//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int S = 1 << 18;
const int T = 10;

int N;
int data[S];
int ftree[S], lis[S], good[S];

void update(int position, int value) {
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


int main() {
    for (int _ = 0; _ < T; _ ++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &data[i]);
        }
        for (int i = 1; i <= N; i ++) {
            ftree[i] = 0;
            good[i] = 0;
        }
        for (int i = 1; i <= N; i ++) {
            lis[i] = get(data[i] - 1) + 1;
            update(data[i], lis[i]);
        }
        int maxLis = 0;
        for (int i = 1; i <= N; i ++) {
            maxLis = max(maxLis, lis[i]);
        }
        vector<vector<pair<int, int>>> f(maxLis + 1);
        vector<vector<int>> candidates(maxLis + 1);
        for (int i = 1; i <= N; i ++) {
            if (lis[i] == maxLis) {
                f[maxLis].push_back(make_pair(i, data[i]));
                good[i] = 1;
            } else {
                candidates[lis[i]].push_back(i);
            }
        }
        for (int i = maxLis - 1; i > 0; i --) {
            for (int j = (int)f[i + 1].size() - 2; j >= 0; j --) {
                f[i + 1][j].second = max(f[i + 1][j].second, f[i + 1][j + 1].second);
            }
            for (int cnd: candidates[i]) {
                auto it = lower_bound(f[i + 1].begin(), f[i + 1].end(), make_pair(cnd, -1));
                if (it != f[i + 1].end() && (*it).second > data[cnd]) {
                    f[i].push_back(make_pair(cnd, data[cnd]));
                    good[cnd] = 1;
                }
            }
        }
        vector<int> result;
        for (int i = 1; i <= N; i ++) {
            if (good[i]) {
                result.push_back(data[i]);
            }
        }
        sort(result.begin(), result.end());
        bool printed = false;
        printf("%d\n", (int)result.size());
        for (auto i: result) {
            if (printed) {
                putchar(' ');
            }
            printf("%d", i);
            printed = true;
        }
        putchar('\n');
    }
    
    return 0;
}
