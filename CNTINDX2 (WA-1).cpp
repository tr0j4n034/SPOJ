//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/20/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * sqrt(N)) solution using STL lists.
 Gets time limit exceeded verdict due to large constant factor.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <list>
#include <cassert>

using namespace std;

const int MAX = 100005;
const int BLOCK_COUNT = 666;
const int BLOCK_SIZE = 333;

int getBlockID(int p) {
    return (p + BLOCK_SIZE - 1) / BLOCK_SIZE;
}
int countInBlock(list<int> &items, int l, int r, int value) {
    int result = 0;
    auto it = items.begin();
    advance(it, l - 1);
    for (int i = 0; i < r - l + 1; i ++) {
        if (*it == value) result ++;
        it ++;
    }
    return result;
}
void print(list<int> &items) {
    for (int i : items) {
        cout << i << ", ";
    }
    cout << endl;
}

int N, Q;
int activeBlocks = 1;
int values[MAX], valueCount[BLOCK_COUNT][MAX];
list<int> blocks[BLOCK_COUNT];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i ++) {
        int data;
        scanf("%d", &data);
        blocks[activeBlocks].push_back(data);
        valueCount[activeBlocks][data] ++;
        if ((int)blocks[activeBlocks].size() == BLOCK_SIZE) ++activeBlocks;
    }
    while (Q --) {
        int type;
        scanf("%d", &type);
        if (type == 1) { // insert
            int position, data;
            scanf("%d%d", &position, &data);
            //assert(position > 0);
            int blockNumber = getBlockID(position);
            auto it = blocks[blockNumber].begin();
            advance(it, position - (blockNumber - 1) * BLOCK_SIZE);
            blocks[blockNumber].insert(it, data);
            for (int i = blockNumber; i <= activeBlocks; i ++) {
                if ((int)blocks[i].size() <= BLOCK_SIZE) {
                    break;
                }
                int lastElement = *(--blocks[i].end());
                blocks[i].pop_back();
                blocks[i + 1].push_front(lastElement);
                valueCount[i][lastElement] --;
                valueCount[i + 1][lastElement] ++;
            }
            if (!blocks[activeBlocks + 1].empty()) ++activeBlocks;
        }
        else if(type == 2) { // update
            int position, newValue;
            scanf("%d%d", &position, &newValue);
            
            if (position == newValue) continue;
            
            int blockNumber = getBlockID(position);
            auto it = blocks[blockNumber].begin();
            advance(it, position - (blockNumber - 1) * BLOCK_SIZE - 1);
            *it = newValue;
            valueCount[blockNumber][values[position]] --;
            values[position] = newValue;
            valueCount[blockNumber][values[position]] ++;
        }
        else { // ask
            int l, r, queryValue;
            scanf("%d%d%d", &l, &r, &queryValue);
            int leftBlockID = getBlockID(l);
            int rightBlockID = getBlockID(r);
            
            if (leftBlockID == rightBlockID) {
                l -= (leftBlockID - 1) * BLOCK_SIZE;
                r -= (leftBlockID - 1) * BLOCK_SIZE;
                printf("%d\n", countInBlock(blocks[leftBlockID], l, r, queryValue));
                continue;
            }
            int result = countInBlock(blocks[leftBlockID], l, BLOCK_SIZE * leftBlockID, queryValue)
            + countInBlock(blocks[rightBlockID], BLOCK_SIZE * (rightBlockID - 1) + 1, r, queryValue);
            for (int i = leftBlockID + 1; i < rightBlockID; i ++) {
                result += valueCount[i][queryValue];
            }
            printf("%d\n", result);
        }
    }
    
    return 0;
}

