//
//  main.cpp
//  practice
//
//  Created by Mahmud on 26/9/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(Q * log^2(N)) solution using lazy segment trees
 Basically, we can keep a lazy segment tree for each letter (a..z)
    to get the count in particular ranges
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int SIZE = 1 << 19;
const int ALPHABET = 26;

int N, Q;
char s[SIZE];
int stree[ALPHABET][SIZE], lazy[ALPHABET][SIZE];

void push(int id, int I, int low, int high) {
    if (lazy[id][I] != -1) {
        stree[id][I] = lazy[id][I] * (high - low + 1);
        if (low != high) {
            lazy[id][I << 1] = lazy[id][I];
            lazy[id][I << 1 | 1] = lazy[id][I];
        }
        lazy[id][I] = -1;
    }
}
void update(int id, int I, int low, int high, int l, int r, int value) {
    push(id, I, low, high);
    if (low > r || high < l) {
        return;
    } if (low >= l && high <= r) {
        lazy[id][I] = value;
        push(id, I, low, high);
        return;
    }
    int middle = (low + high) >> 1;
    update(id, I << 1, low, middle, l, r, value);
    update(id, I << 1 | 1, middle + 1, high, l, r, value);
    stree[id][I] = stree[id][I << 1] + stree[id][I << 1 | 1];
}
//int getKthElement(int id, int I, int low, int high, int K) {
//    push(id, I, low, high);
//    if (low == high) {
//        if (K == 1) {
//            return low;
//        } else {
//            return -1;
//        }
//    }
//    int middle = (low + high) >> 1;
//    push(id, I << 1, low, middle);
//    int skips = stree[id][I << 1];
//    if (skips >= K) {
//        return getKthElement(id, I << 1, low, middle, K);
//    } else {
//        return getKthElement(id, I << 1 | 1, middle + 1, high, K - skips);
//    }
//}

int get(int id, int I, int low, int high, int l, int r) {
    push(id, I, low, high);
    if (low > r || high < l) {
        return 0;
    } if (low >= l && high <= r) {
        return stree[id][I];
    }
    int middle = (low + high) >> 1;
    return get(id, I << 1, low, middle, l, r)
    + get(id, I << 1 | 1, middle + 1, high, l, r);
}
int getKthElement(int id, int I, int K) {
    int low = 1, high = N, middle, best = -1;
    while (low <= high) {
        middle = (low + high) >> 1;
        if (get(id, 1, 1, N, 1, middle) >= K) {
            best = middle;
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return best;
}

int main() {
    char ch;
    N = 0;
    while (1) {
        ch = getchar();
        if (ch == '\n') {
            break;
        } s[++N] = ch;
    }
    for (int i = 0; i < ALPHABET; i ++) {
        for (int j = 1; j < SIZE; j ++) {
            lazy[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; i ++) {
        update(s[i] - 'a', 1, 1, N, i, i, +1);
    }
    cin >> Q;
    while (Q --) {
        int type, l, r;
        char ch;
        scanf("%d", &type);
        if (type == 0) {
            scanf("%d%d %c", &l, &r, &ch);
            for (int i = 0; i < ALPHABET; i ++) {
                update(i, 1, 1, N, l, r, (ch - 'a' == i) ? +1 : 0);
            }
        } else {
            scanf("%d %c", &l, &ch);
            printf("%d\n", getKthElement(ch - 'a', 1, l));
        }
    }
    
    return 0;
}
