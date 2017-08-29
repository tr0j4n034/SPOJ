//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/29/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


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
int bruteSolveCombined (int low, int high) {
    int lowBlockID = getBlockID(low);
    int highBlockID = getBlockID(high);
    int pairs = 0;
    for (int i = low; i <= lowBlockID * MAGIC; i ++) {
        for (int j = (highBlockID - 1) * MAGIC + 1; j <= high; j ++) {
            if (data[i] - data[j] >= K || data[j] - data[i] >= K) {
                pairs ++;
            }
        }
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
int bruteSolveExtra (int low, int high, int lowBlockID, int highBlockID) {
    int pairs = 0;
    for (int i = low; i <= high; i ++) {
        for (int j = (lowBlockID - 1) * MAGIC + 1; j <= min(N, highBlockID * MAGIC); j ++) {
            if (data[i] - data[j] >= K || data[j] - data[i] >= K) {
                pairs ++;
            }
        }
    }
    return pairs;
}
int solveBrute (int low, int high) {
    int pairs = 0;
    for (int i = low; i <= high; i ++) {
        for (int j = i + 1; j <= high; j ++) {
            if (data[i] - data[j] >= K || data[j] - data[i] >= K) {
                pairs ++;
            }
        }
    }
    return pairs;
}

void generateTest () {
    srand(unsigned(time(NULL)));
    N = rand() % 30000;
    M = rand() % 30000;
    K = rand() % 100000 + 1;
    cout << "N = " << N << ", M = " << M << endl;
    for (int i = 1; i <= N; i ++) {
        data[i] = rand() % 100000 + 1;
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &data[i]);
    }
    //generateTest();
    assert(K > 0 && K < (1 << 20));
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
    
    /*
     for (int i = 1; i <= blocksCount; i ++) {
     for (int j = i; j <= blocksCount; j ++) {
     int brute = solveBrute((i - 1) * MAGIC + 1, min(j * MAGIC, N));
     if (dpOnBlocks[i][j] != brute) {
     cout << i << " vs " << j << " ---> " << dpOnBlocks[i][j] << " and " << brute << endl;
     }
     assert(dpOnBlocks[i][j] == brute);
     }
     }
     cout << "table is okay" << endl;
     */
    
    /*
     for (int i = 0; i < 200; i ++) {
     int l = rand() % N + 1;
     int r = rand() % N + 1;
     if (l > r) {
     swap(l, r);
     }
     if (getBlockID(l) == getBlockID(r)) {
     continue;
     }
     assert (solveCombined(l, r) == bruteSolveCombined(l, r));
     }
     cout << "solve combined is okay" << endl;
     */
    
    
    /*
     // solving ranges is okay
     for (int i = 0; i < 200; i ++) {
     int l = rand() % N + 1;
     int r = rand() % N + 1;
     if (l > r) {
     swap(l, r);
     }
     if (getBlockID(l) != getBlockID(r)) {
     continue;
     }
     assert(solveBrute(l, r) == solveRange(l, r));
     }
     */
    /*
     for (int i = 0; i < 200; i ++) {
     int l = rand() % N;
     int r = l + rand() % MAGIC;
     if (l > r) {
     swap(l, r);
     }
     if (getBlockID(l) != getBlockID(r)) {
     continue;
     }
     if (getBlockID(l) == getBlockID(N)) {
     continue;
     }
     int lowBlockID = rand() % blocksCount + 1;
     if (lowBlockID < getBlockID(l)) {
     continue;
     }
     int highBlockID = rand() % blocksCount + 1;
     if (highBlockID < getBlockID(l)) {
     continue;
     }
     if (lowBlockID < highBlockID) {
     swap(lowBlockID, highBlockID);
     }
     assert(solveExtra(l, r, lowBlockID, highBlockID) == bruteSolveExtra(l, r, lowBlockID, highBlockID));
     }
     */
    
    //cout << "okay" << endl;
    //return 0;
    
    while (M --) {
        int l, r;
        scanf("%d%d", &l, &r);
        //l = rand() % N + 1;
        //r = rand() % N + 1;
        //if (l > r) {
        //    swap(l, r);
        //}
        int leftBlockID = getBlockID(l);
        int rightBlockID = getBlockID(r);
        if (leftBlockID == rightBlockID) {
            assert(solveBrute(l, r) == solveRange(l, r));
            printf("%d\n", solveRange(l, r));
            continue;
        }
        int p[6];
        int result = 0;
        result += (leftBlockID + 1 < rightBlockID ? dpOnBlocks[leftBlockID + 1][rightBlockID - 1] : 0);
        p[0] = result;
        //assert(result >= 0);
        result += solveRange(l, getBlockID(l) * MAGIC);
        p[1] = result;
        //assert(solveBrute(l, getBlockID(l) * MAGIC) == p[1] - p[0]);
        //assert(result >= 0);
        result += solveRange((getBlockID(r) - 1) * MAGIC + 1, r);
        p[2] = result;
        //assert(solveBrute((getBlockID(r) - 1) * MAGIC + 1, r) == p[2] - p[1]);
        //assert(result >= 0);
        result += solveCombined(l, r);
        p[3] = result;
        //assert(bruteSolveCombined(l, r) == p[3] - p[2]);
        //assert(result >= 0);
        result += solveExtra(l, getBlockID(l) * MAGIC, leftBlockID + 1, rightBlockID - 1);
        p[4] = result;
        //assert(bruteSolveExtra(l, getBlockID(l) * MAGIC, leftBlockID + 1, rightBlockID - 1) == p[4] - p[3]);
        //assert(result >= 0);
        result += solveExtra((getBlockID(r) - 1) * MAGIC + 1, r, leftBlockID + 1, rightBlockID - 1);
        p[5] = result;
        //assert(bruteSolveExtra((getBlockID(r) - 1) * MAGIC + 1, r, leftBlockID + 1, rightBlockID - 1) == p[5] - p[4]);
        //int brute = solveBrute(l, r);
        //if (result != brute) {
        //    cout << "L = " << l << ", and R = " << r << endl;
        //    for (int i = 0; i < 5; i ++) {
        //        cout << p[i] << ", ";
        //    }
        //    cout << endl;
        //    cout << "result = " << result << endl;
        //    cout << "brute = " << brute << endl;
        //}
        //assert(result == solveBrute(l, r));
        printf("%d\n", result);
    }
    
    return 0;
}
