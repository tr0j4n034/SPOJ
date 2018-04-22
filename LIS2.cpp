//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#pragma GCC optimize("-0g")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100005;

int N, Nx, Ny;
int x[MAX], y[MAX];
int dp[MAX];
vector<int> gridValues[MAX];
vector<int> compressedFenwick[MAX];

void update(vector<int> &fenwick, int position, int treeSize, int value) {
    for ( ; position <= treeSize; position += (position & -position)) {
        fenwick[position] = max(fenwick[position], value);
    }
}
int get(vector<int> &fenwick, int position) {
    int s = 0;
    for ( ; position > 0; position -= (position & -position)) {
        s = max(s, fenwick[position]);
    }
    return s;
}

template <class T>
void fastInput(T &N) {
    char ch;
    int sign = 1;
    N = 0;
    while ((ch = getchar_unlocked()) && ch == ' ') {};
    if (ch == '-') sign = -1;
    else if (isdigit(ch)) N = ch - '0';
    while ((ch = getchar_unlocked()) && isdigit(ch)) {
        N = (N << 1) + (N << 3) + ch - '0';
    }
    if (sign == -1) N = ~N + 1;
}

int main() {
    //scanf("%d", &N);
    fastInput(N);
    //for (int i = 1; i <= N; i ++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= N; i ++) {
        fastInput(x[i]);
        fastInput(y[i]);
    }
    vector<int> values = vector<int> (x + 1, x + N + 1);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 1; i <= N; i ++) {
        x[i] = (int)(lower_bound(values.begin(), values.end(), x[i]) - values.begin()) + 1;
    }
    Nx = (int)values.size();
    values = vector<int> (y + 1, y + N + 1);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 1; i <= N; i ++) {
        y[i] = (int)(lower_bound(values.begin(), values.end(), y[i]) - values.begin()) + 1;
    }
    Ny = (int)values.size();
    
    for (int i = 1; i <= N; i ++) {
        for (int j = x[i] - 1; j > 0; j -= (j & -j)) {
            gridValues[j].push_back(y[i]);
        }
        for (int j = x[i]; j <= Nx; j += (j & -j)) {
            //cout << "adding: " << i << " " << j << endl;
            gridValues[j].push_back(y[i]);
        }
    }
    for (int i = 1; i <= Nx; i ++) {
        gridValues[i].push_back(N);
        sort(gridValues[i].begin(), gridValues[i].end());
        gridValues[i].erase(unique(gridValues[i].begin(), gridValues[i].end()), gridValues[i].end());
        compressedFenwick[i].resize((int)gridValues[i].size() + 1, 0);
    }
    int result = 0;
    for (int i = 1; i <= N; i ++) {
        dp[i] = 1;
        for (int j = x[i] - 1; j > 0; j -= (j & -j)) {
            int currentY = (int)(lower_bound(gridValues[j].begin(), gridValues[j].end(), y[i]) - gridValues[j].begin()) + 1;
            dp[i] = max(dp[i], get(compressedFenwick[j], currentY - 1) + 1);
        }
        for (int j = x[i]; j <= Nx; j += (j & -j)) {
            int currentY = (int)(lower_bound(gridValues[j].begin(), gridValues[j].end(), y[i]) - gridValues[j].begin()) + 1;
            update(compressedFenwick[j], currentY, (int)compressedFenwick[j].size(), dp[i]);
        }
        result = max(result, dp[i]);
    }
    
    cout << result << endl;
    
    return 0;
}
