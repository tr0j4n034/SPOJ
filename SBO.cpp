//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/29/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * log(N)) solution using lazy segment trees
 Let's consider we know the result for each suffix ending at i-th position.
 Now, the current result (maximum suffix ending at i + 1)
  can be calculated with range queries considering previous occurences of the current element.
 For each case, just update the corresponding segment.
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 500005;

int N;
int data[MAX];
int stree[MAX << 2], lazy[MAX << 2];
vector<int> occurences[MAX];

void push(int I, int low, int high) {
    if (lazy[I] != 0) {
        stree[I] += lazy[I];
        if (low != high) {
            lazy[I << 1] += lazy[I];
            lazy[I << 1 | 1] += lazy[I];
        }
        lazy[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r, int value) {
    if (low > high) return; // ~~
    push(I, low, high);
    if (low > r || high < l) return;
    if (low >= l && high <= r) {
        lazy[I] += value;
        push(I, low, high);
        return;
    }
    int middle = (low + high) >> 1;
    update(I << 1, low, middle, l, r, value);
    update(I << 1 | 1, middle + 1, high, l, r, value);
    stree[I] = max(stree[I << 1], stree[I << 1 | 1]);
}
int get(int I, int low, int high, int l, int r) {
    if (low > high) return 0; // ~~
    push(I, low, high);
    if (low > r || high < l) return 0;
    if (low >= l && high <= r) return stree[I];
    int middle = (low + high) >> 1;
    return max(get(I << 1, low, middle, l, r),
               get(I << 1 | 1, middle + 1, high, l, r));
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
    fastInput(N);
    for (int i = 1; i <= N; i ++) fastInput(data[i]);
    for (int i = 1; i <= N; i ++) {
        if (occurences[data[i]].empty()) occurences[data[i]].push_back(0);
    }
    
    int result = 0;
    for (int i = 1; i <= N; i ++) {
        int current = 0;
        int count = (int)occurences[data[i]].size();
        current = get(1, 1, N, occurences[data[i]].back() + 1, i - 1) + 1;
        update(1, 1, N, occurences[data[i]].back() + 1, i, +1);
        if (count == 1);
        else if (count == 2) {
            current = max(current, get(1, 1, N, 1, occurences[data[i]][1]) - 1);
            update(1, 1, N, 1, occurences[data[i]][1], -1);
        }
        else {
            current = max(current,
                          get(1, 1, N, occurences[data[i]][count - 2] + 1, occurences[data[i]][count - 1]) - 1);
            update(1, 1, N, occurences[data[i]][count - 2] + 1, occurences[data[i]][count - 1], -1);
            current = max(current,
                          get(1, 1, N, 1, occurences[data[i]][count - 2]));
        }
        occurences[data[i]].push_back(i);
        result = max(result, current);
    }
    
    cout << result << endl;
    
    return 0;
}

