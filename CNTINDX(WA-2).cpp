//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/24/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O((N + Q) * sqrt(N)) solution using sqrt decomposition
 
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int BLOCK_COUNT = 666;
const int BLOCK_SIZE = 333;
const int MAX = 100005;
const int OFFSET = 100005;

int N, Q;
int blockStart[BLOCK_COUNT], blockEnd[BLOCK_COUNT], activeSize[BLOCK_COUNT];
int data[BLOCK_COUNT][MAX << 1], occurrences[BLOCK_COUNT][MAX];

int getBlockId(int N) {
    return (N + BLOCK_SIZE - 1) / BLOCK_SIZE;
}
void pushBack(int blockID, int value) {
    data[blockID][++blockEnd[blockID]] = value;
    occurrences[blockID][value] ++;
    activeSize[blockID] ++;
}
void pushFront(int blockID, int value) {
    if (activeSize[blockID] == 0) {
        pushBack(blockID, value);
        return;
    }
    data[blockID][--blockStart[blockID]] = value;
    occurrences[blockID][value] ++;
    activeSize[blockID] ++;
    if (activeSize[blockID] > BLOCK_SIZE) {
        int lastElement = data[blockID][blockEnd[blockID]];
        occurrences[blockID][lastElement] --;
        blockEnd[blockID] --;
        activeSize[blockID] --;
        pushFront(blockID + 1, lastElement);
    }
}
void insert(int blockID, int position, int value) {
    int blockPosition = position - (blockID - 1) * BLOCK_SIZE;
    for (int i = blockEnd[blockID] + 1; i > blockStart[blockID] + position; i --) {
        data[blockID][i] = data[blockID][i - 1];
    }
    data[blockID][blockStart[blockID] + blockPosition] = value;
    blockEnd[blockID] ++;
    occurrences[blockID][value] ++;
    if (activeSize[blockID] > BLOCK_SIZE) {
        int lastElement = data[blockID][blockEnd[blockID]];
        occurrences[blockID][lastElement] --;
        blockEnd[blockID] --;
        activeSize[blockID] --;
        pushFront(blockID + 1, lastElement);
    }
}
int countInBlock(int blockID, int l, int r, int value) {
    int s = 0;
    int blockPosition = l - (blockID - 1) * BLOCK_SIZE;
    for (int i = 0; i < r - l + 1; i ++) {
        if (data[blockID][blockStart[blockID] + blockPosition + i - 1] == value) {
            s ++;
        }
    }
    return s;
}
void print(int blockID) {
    for (int i = blockStart[blockID]; i <= blockEnd[blockID]; i ++) {
        cout << data[blockID][i] << ", ";
    }
    cout << endl;
}

int main() {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i < BLOCK_COUNT; i ++) {
        blockStart[i] = OFFSET;
        blockEnd[i] = OFFSET - 1;
        activeSize[i] = 0;
    }
    for (int i = 1; i <= N; i ++) {
        int value;
        scanf("%d", &value);
        pushBack(getBlockId(i), value);
    }
    while (Q --) {
        print(1);
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int position, value;
            scanf("%d%d", &position, &value);
            if (position % BLOCK_SIZE == 0) {
                pushFront(getBlockId(position + 1), value);
            }
            else {
                insert(getBlockId(position), position, value);
            }
        }
        else if(type == 2) {
            int position, newValue;
            scanf("%d%d", &position, &newValue);
            int blockID = getBlockId(position);
            int blockPosition = position - (blockID - 1) * BLOCK_SIZE;
            int oldValue = data[blockID][blockStart[blockID] + blockPosition - 1];
            occurrences[blockID][oldValue] --;
            data[blockID][blockStart[blockID] + blockPosition - 1] = newValue;
            occurrences[blockID][newValue] ++;
        }
        else {
            int l, r, value;
            scanf("%d%d%d", &l, &r, &value);
            int leftBlockID = getBlockId(l);
            int rightBlockID = getBlockId(r);
            if (leftBlockID == rightBlockID) {
                printf("%d\n", countInBlock(leftBlockID, l, r, value));
                continue;
            }
            int result = 0;
            result += countInBlock(leftBlockID, l, leftBlockID * BLOCK_SIZE, value);
            result += countInBlock(rightBlockID, (rightBlockID - 1) * BLOCK_SIZE + 1, r, value);
            for (int i = leftBlockID + 1; i < rightBlockID; i ++) {
                result += occurrences[i][value];
            }
            printf("%d\n", result);
        }
    }
    
    return 0;
}

