//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/31/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 50005;
const int OFFSET = 50005;
const int SIZE = 100015;
const int MAGIC = 246;

struct query{
    int l, r, id;
    query () {
        
    }
    query (int l, int r, int id):
    l(l), r(r), id(id){
        
    }
    bool operator < (const query other)const{
        if(l / MAGIC != other.l / MAGIC) {
            return l / MAGIC < other.l / MAGIC;
        }
        return r < other.r;
    }
};

int N, Q;
int currentAnswer;
int data[MAX], prefix[MAX];
int optimumInBlocks[MAGIC][MAGIC];
int output[MAX];
vector<int> occurence[SIZE];

int valid(int x, int l, int r) {
    return x >= l && x <= r;
}
int initializeTable(int lowBlockID, int highBlockID) {
    if(lowBlockID > highBlockID) {
        return 0;
    }
    if(optimumInBlocks[lowBlockID][highBlockID] != -1) {
        return optimumInBlocks[lowBlockID][highBlockID];
    }
    if(lowBlockID == highBlockID) {
        int best = 0;
        for(int i = (lowBlockID - 1) * MAGIC + 1; i <= min(N, lowBlockID * MAGIC); i ++) {
            int sum = prefix[i - 1] + OFFSET;
            auto nextPosition = --lower_bound(occurence[sum].begin(),
                                              occurence[sum].end(),
                                              lowBlockID * MAGIC + 1)
            - occurence[sum].begin();
            if(valid(occurence[sum][(int)nextPosition], i, min(N, lowBlockID * MAGIC))) {
                best = max(best, occurence[sum][(int)nextPosition] - i + 1);
            }
        }
        return optimumInBlocks[lowBlockID][highBlockID] = best;
    }
    int currentBest = 0;
    currentBest = max(initializeTable(lowBlockID, highBlockID - 1),
                      initializeTable(lowBlockID + 1, highBlockID));
    
    for(int i = (lowBlockID - 1) * MAGIC + 1; i <= min(N, lowBlockID * MAGIC); i ++) {
        int sum = prefix[i - 1] + OFFSET;
        auto nextPosition = --lower_bound(occurence[sum].begin(),
                                          occurence[sum].end(),
                                          highBlockID * MAGIC + 1)
        - occurence[sum].begin();
        if(valid(occurence[sum][(int)nextPosition], i, min(N, highBlockID * MAGIC))) {
            currentBest = max(currentBest, occurence[sum][(int)nextPosition] - i + 1);
        }
    }
    for(int i = (highBlockID - 1) * MAGIC + 1; i <= min(N, highBlockID * MAGIC); i ++) {
        int sum = prefix[i] + OFFSET;
        auto nextPosition = lower_bound(occurence[sum].begin(),
                                        occurence[sum].end(),
                                        (lowBlockID - 1) * MAGIC + 1)
        - occurence[sum].begin();
        
        if(valid(occurence[sum][(int)nextPosition], (lowBlockID - 1) * MAGIC + 1, i)) {
            currentBest = max(currentBest, i - occurence[sum][(int)nextPosition]);
        }
    }
    return optimumInBlocks[lowBlockID][highBlockID] = currentBest;
}

void generateTest(){
    srand(unsigned(time(NULL)));
    N = rand() % 777 + 1;
    Q = rand() % 2000;
    cout << "N = " << N << ", Q = " << Q << endl;
    for(int i = 1; i <= N; i ++) {
        data[i] = ((rand() & 1) ? 1 : -1);
    }
}

int main(int argc, const char * argv[]) {
    //generateTest();
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i ++) {
        scanf("%d", &data[i]);
    }
    for(int i = 0; i <= N; i ++) {
        prefix[i] = (i > 0 ? prefix[i - 1] : 0) + data[i];
        occurence[prefix[i] + OFFSET].push_back(i);
    }
    for(int i = 0; i < MAGIC; i ++) {
        for(int j = i; j < MAGIC; j ++) {
            optimumInBlocks[i][j] = -1;
        }
    }
    int BLOCK_COUNT = (N + MAGIC - 1) / MAGIC;
    initializeTable(1, BLOCK_COUNT);
    //for(int i = 1; i <= BLOCK_COUNT; i ++) {
    //    for(int j = i; j <= BLOCK_COUNT; j ++) {
    //        int best = 0;
    //        int st = (i - 1) * MAGIC + 1;
    //        int fn = min(N, j * MAGIC);
    //        for(int k = st; k <= fn; k ++) {
    //            int sum = 0;
    //            for(int q = k; q <= fn; q ++) {
    //                sum += data[q];
    //                if(sum == 0) {
    //                    best = max(best, q - k + 1);
    //                }
    //            }
    //        }
    //        assert(optimumInBlocks[i][j] == best);
    //    }
    //
    //}
    
    
    while(Q --) {
        int l, r;
        scanf("%d%d", &l, &r);
        //l = rand() % N + 1;
        //r = rand() % N + 1;
        //if(l > r) {
        //    swap(l, r);
        //}
        //int brute = 0;
        //for(int i = l; i <= r; i ++) {
        //    int sum = 0;
        //    for(int j = i; j <= r; j ++) {
        //        sum += data[j];
        //        if(sum == 0) {
        //            brute = max(brute, j - i + 1);
        //        }
        //    }
        //}
        //cout << "brute: " << brute << endl;
        
        int lowBlockID = (l + MAGIC - 1) / MAGIC;
        int highBlockID = (r + MAGIC - 1) / MAGIC;
        int result = 0;
        if(lowBlockID == highBlockID) {
            for(int i = l; i <= r; i ++) {
                int sum = prefix[i - 1] + OFFSET;
                auto nextPosition = --upper_bound(occurence[sum].begin(), occurence[sum].end(), r)
                - occurence[sum].begin();
                if(valid(occurence[sum][(int)nextPosition], l, r)) {
                    result = max(result, occurence[sum][nextPosition] - i + 1);
                }
            }
        }
        else {
            result = max(result, optimumInBlocks[lowBlockID + 1][highBlockID - 1]);
            for(int i = l; i <= min(N, lowBlockID * MAGIC); i ++) {
                //assert(i <= r && i >= l);
                int sum = prefix[i - 1] + OFFSET;
                auto nextPosition = --upper_bound(occurence[sum].begin(), occurence[sum].end(), r)
                - occurence[sum].begin();
                if(valid(occurence[sum][(int)nextPosition], l, r)) {
                    result = max(result, occurence[sum][nextPosition] - i + 1);
                }
            }
            for(int i = r; i >= (highBlockID - 1) * MAGIC + 1; i --) {
                //assert(i >= l && i <= r);
                int sum = prefix[i] + OFFSET;
                auto nextPosition = lower_bound(occurence[sum].begin(), occurence[sum].end(), l)
                - occurence[sum].begin();
                if(valid(occurence[sum][(int)nextPosition], l, r)) {
                    result = max(result, i - occurence[sum][nextPosition]);
                }
            }
        }
        //cout << "my solution: ";
        printf("%d\n", result);
        //if(result != brute) {
        //    cout << "problem occured" << endl;
        //    cout << "l = " << l << ", r = " << r << endl;
        //    return 0;
        //}
    }
    
    return 0;
}
