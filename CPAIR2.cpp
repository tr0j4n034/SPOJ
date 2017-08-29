//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/29/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 An O(Q * sqrt(N)) solution with a huge constant.
 Queries are processed in five stages...
 Prefix table is used to count the number of elements in a range in O(1) time.
 */


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <vector>
#include <utility>

using namespace std;

const int SIZE = 50005;
const int MAX = SIZE << 1;
const int MAGIC = 234;

int N, M, K;
int data[SIZE];
int prefixTable[MAGIC][MAX];
int dpOnBlocks[MAGIC][MAGIC];
vector<pair<int, int>> sortedBlock[MAGIC];

int getBlockID (int position) {
    return (position + MAGIC - 1) / MAGIC;
}
int solve (vector<pair<int, int>> &orderedList) {
    int listSize = (int)orderedList.size();
    int ptr = 0;
    int pairs = 0;
    for (int i = 0; i < listSize; i ++) {
        while (ptr < listSize && orderedList[ptr].first - orderedList[i].first < K) {
            ptr ++;
        }
        pairs += listSize - ptr;
    }
    return pairs;
}
int initializeTable (int lowBlockID, int highBlockID) {
    if (lowBlockID > highBlockID) {
        return 0;
    }
    if (dpOnBlocks[lowBlockID][highBlockID] != -1) {
        return dpOnBlocks[lowBlockID][highBlockID];
    }
    if (lowBlockID == highBlockID) {
        return dpOnBlocks[lowBlockID][highBlockID] = solve(sortedBlock[lowBlockID]);
    }
    int pairs = 0;
    pairs += initializeTable(lowBlockID, highBlockID - 1);
    pairs += solve(sortedBlock[highBlockID]);
    for (int i = (highBlockID - 1) * MAGIC + 1; i <= min(N, highBlockID * MAGIC); i ++) {
        if (data[i] > K) {
            pairs += prefixTable[highBlockID - 1][data[i] - K] - prefixTable[lowBlockID - 1][data[i] - K];
        }
        if (data[i] + K < MAX) {
            int add = (highBlockID - 1) * MAGIC - prefixTable[highBlockID - 1][data[i] + K - 1];
            int remove = (lowBlockID - 1) * MAGIC - prefixTable[lowBlockID - 1][data[i] + K - 1];
            pairs += add - remove;
        }
    }
    return dpOnBlocks[lowBlockID][highBlockID] = pairs;
}
bool isInRange (int x, int l, int r) {
    return x >= l && x <= r;
}
int solveRange (int low, int high) {
    int cnt = high - low + 1;
    int skipped = 0;
    int pairs = 0;
    int ptr = 0;
    int blockID = getBlockID(low);
    int blockSize = (int)sortedBlock[blockID].size();
    for (int i = 0; i < blockSize; i ++) {
        if (!isInRange(sortedBlock[blockID][i].second, low, high)) {
            continue;
        }
        while (ptr < blockSize) {
            if (!isInRange(sortedBlock[blockID][ptr].second, low, high)) {
                ptr ++;
                continue;
            }
            if (sortedBlock[blockID][ptr].first - sortedBlock[blockID][i].first >= K) {
                break;
            }
            skipped ++;
            ptr ++;
        }
        pairs += cnt - skipped;
    }
    return pairs;
}

int tempTable[2][MAGIC];
int tempSize[2];

int solveCombined (int low, int high) {
    int lowBlockID = getBlockID(low);
    int highBlockID = getBlockID(high);
    int pairs = 0;
    tempSize[0] = tempSize[1] = 0;
    for (auto i : sortedBlock[lowBlockID]) {
        if (i.second >= low) {
            tempTable[0][tempSize[0] ++] = i.first;
        }
    }
    for (auto i : sortedBlock[highBlockID]) {
        if (i.second <= high) {
            tempTable[1][tempSize[1] ++] = i.first;
        }
    }
    int ptr = 0;
    for (int i = 0; i < tempSize[0]; i ++) {
        while (ptr < tempSize[1] && tempTable[1][ptr] < tempTable[0][i] + K) {
            ptr ++;
        }
        pairs += tempSize[1] - ptr;
    }
    ptr = 0;
    for (int i = 0; i < tempSize[1]; i ++) {
        while (ptr < tempSize[0] && tempTable[0][ptr] < tempTable[1][i] + K) {
            ptr ++;
        }
        pairs += tempSize[0] - ptr;
    }
    return pairs;
}
int solveExtra (int low, int high, int lowBlockID, int highBlockID) {
    if (lowBlockID > highBlockID) {
        return 0;
    }
    int pairs = 0;
    for (int i = low; i <= high; i ++) {
        if (data[i] > K) {
            pairs += prefixTable[highBlockID][data[i] - K] - prefixTable[lowBlockID - 1][data[i] - K];
        }
        if (data[i] + K < MAX) {
            int add = min(N, highBlockID * MAGIC) - prefixTable[highBlockID][data[i] + K - 1];
            int remove = (lowBlockID - 1) * MAGIC - prefixTable[lowBlockID - 1][data[i] + K - 1];
            pairs += add - remove;
        }
    }
    return pairs;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &data[i]);
    }
    int blocksCount = getBlockID(N);
    for (int i = 1; i <= blocksCount; i ++) {
        for (int j = (i - 1) * MAGIC + 1; j <= min(i * MAGIC, N); j ++) {
            prefixTable[i][data[j]] ++;
        }
        for (int j = 1; j < MAX; j ++) {
            prefixTable[i][j] += prefixTable[i][j - 1];
        }
        for (int j = 1; j < MAX; j ++) {
            prefixTable[i][j] += prefixTable[i - 1][j];
        }
    }
    for (int i = 1; i <= N; i ++) {
        sortedBlock[(i + MAGIC - 1) / MAGIC].push_back(make_pair(data[i], i));
    }
    for (int i = 1; i < MAGIC; i ++) {
        sort(sortedBlock[i].begin(), sortedBlock[i].end());
    }
    for (int i = 1; i < MAGIC; i ++) {
        for (int j = i; j < MAGIC; j ++) {
            dpOnBlocks[i][j] = -1;
        }
    }
    for (int i = 1; i <= blocksCount; i ++) {
        for (int j = 1; j <= blocksCount; j ++) {
            initializeTable(i, j);
        }
    }
    while (M --) {
        int l, r;
        scanf("%d%d", &l, &r);
        int leftBlockID = getBlockID(l);
        int rightBlockID = getBlockID(r);
        if (leftBlockID == rightBlockID) {
            printf("%d\n", solveRange(l, r));
            continue;
        }
        int result = 0;
        result += (leftBlockID + 1 < rightBlockID ? dpOnBlocks[leftBlockID + 1][rightBlockID - 1] : 0);
        result += solveRange(l, getBlockID(l) * MAGIC);
        result += solveRange((getBlockID(r) - 1) * MAGIC + 1, r);
        result += solveCombined(l, r);
        result += solveExtra(l, getBlockID(l) * MAGIC, leftBlockID + 1, rightBlockID - 1);
        result += solveExtra((getBlockID(r) - 1) * MAGIC + 1, r, leftBlockID + 1, rightBlockID - 1);
        printf("%d\n", result);
    }
    
    return 0;
}
