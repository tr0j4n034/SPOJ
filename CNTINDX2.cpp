//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/19/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O((N + Q) * sqrt(N)) solution
    using "Split & Rebuild" technique.
 */

#include <iostream>
#include <cstdio>

#pragma GCC optimize("-0g")

using namespace std;

const int S = 200005;
const int MAX_VALUE = 100005;
const int BLOCKS_COUNT = 550;
const int BLOCK_SIZE = 350;

int N, Q;
int a[S], id[S];
int counts[BLOCKS_COUNT][MAX_VALUE];
int blockSize[BLOCKS_COUNT];
int blocks[BLOCKS_COUNT][BLOCK_SIZE * 2 + 5];

void rebuild() {
    N = 0;
    for (int i = 1; i < BLOCKS_COUNT; i ++) {
        for (int j = 1; j <= blockSize[i]; j ++) {
            a[++N] = blocks[i][j];
            counts[i][blocks[i][j]] = 0;
        }
        blockSize[i] = 0;
    }
    for (int i = 1; i <= N; i ++) {
        blocks[id[i]][++blockSize[id[i]]] = a[i];
        counts[id[i]][a[i]] ++;
    }
}
void insert(int position, int value) {
    int skipped = 0;
    for (int i = 1; i < BLOCKS_COUNT; i ++) {
        if (skipped + blockSize[i] < position) {
            skipped += blockSize[i];
            continue;
        }
        int put = position - skipped + 1;
        for (int j = blockSize[i] + 1; j > put; j --) {
            blocks[i][j] = blocks[i][j - 1];
        }
        blocks[i][put] = value;
        ++blockSize[i];
        counts[i][value] ++;
        break;
    }
}
void update(int position, int value) {
    int skipped = 0;
    for (int i = 1; i < BLOCKS_COUNT; i ++) {
        if (skipped + blockSize[i] < position) {
            skipped += blockSize[i];
            continue;
        }
        int put = position - skipped;
        counts[i][blocks[i][put]] --;
        blocks[i][put] = value;
        counts[i][value] ++;
        break;
    }
}
int getCount(int l, int r, int value) {
    int skipped = 0;
    int s = 0;
    for (int i = 1; i < BLOCKS_COUNT; i ++) {
        if (blockSize[i] == 0) {
            break;
        }
        int from = skipped + 1;
        int to = skipped + blockSize[i];
        if (from > r) {
            break;
        } else if (to < l) {
            skipped = to;
        } else if (from >= l && to <= r) {
            s += counts[i][value];
            skipped = to;
        } else {
            int current = skipped;
            for (int j = 1; j <= blockSize[i]; j ++) {
                current ++;
                if (current >= l && current <= r) {
                    s += (int)(blocks[i][j] == value);
                }
            }
            skipped = to;
        }
    }
    return s;
}

template <class T>
void fastInput(T &N) {
    char ch;
    N = 0;
    while ((ch = getchar_unlocked()) && ch == ' ') {};
    if (isdigit(ch)) N = ch - '0';
    while ((ch = getchar_unlocked()) && isdigit(ch)) {
        N = (N << 1) + (N << 3) + ch - '0';
    }
}
template<class T> void fastPrint(T n){
    if(n == 0){
        puts("0");
        return;
    }
    char buffer[256];
    int ptr = 0;
    
    while(n > 0){
        buffer[ptr ++] = (char)(n % 10 + '0');
        n /= 10;
    }
    for(int i = ptr - 1; i >= 0; i --)
        putchar_unlocked(buffer[i]);
    putchar_unlocked('\n');
}

int main() {
    for (int i = 1; i < S; i ++) {
        id[i] = (i + BLOCK_SIZE - 1) / BLOCK_SIZE;
    }
    //scanf("%d%d", &N, &Q);
    fastInput(N);
    fastInput(Q);
    for (int i = 1; i <= N; i ++) {
        //scanf("%d", &a[i]);
        fastInput(a[i]);
    }
    for (int i = 1; i <= N; i ++) {
        blocks[id[i]][++blockSize[id[i]]] = a[i];
        counts[id[i]][a[i]] ++;
    }
    while (Q --) {
        int type;
        //scanf("%d", &type);
        fastInput(type);
        if (type == 1) { // insert
            int x, y;
            //scanf("%d%d", &x, &y);
            fastInput(x);
            fastInput(y);
            insert(x, y);
        }
        else if (type == 2) { // update
            int x, y;
            //scanf("%d%d", &x, &y);
            fastInput(x);
            fastInput(y);
            update(x, y);
        }
        else { // count
            int l, r, x;
            //scanf("%d%d%d", &l, &r, &x);
            fastInput(l);
            fastInput(r);
            fastInput(x);
            printf("%d\n", getCount(l, r, x));
        }
        if (Q % (BLOCK_SIZE << 1) == 0) {
            rebuild();
        }
    }
    
    return 0;
}
