//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/06/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * K * K * log(C)) solution.
 As the value of C is small, just keep coordinates of C nearest points for every cheese.
 Now, check all possible starting points, everytime we need to conside only C neearest neighbors.
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 1005;
const int SIZE = 11;

int T, N, K, C;
string gridLine;
int x[MAX], y[MAX];
int d[MAX][MAX];

struct neighbor{
    int d; // distance
    int id; // id
    neighbor() {
        
    }
    neighbor(int _d, int _id):
    d(_d), id(_id) {
        
    }
    bool operator < (const neighbor other) const{
        if (d != other.d) { // compare distances
            return d < other.d;
        }
        if (x[id] != x[other.id]) { // compare x coordinates
            return x[id] < x[other.id];
        }
        return y[id] < y[other.id]; // compare y coordinates
    }
};

int usedID[SIZE];
int alreadyUsed[MAX];
set<neighbor> nearest[MAX];

int main() {
    cin >> T;
    while (T --) {
        cin >> N >> K >> C;
        K = 0;
        for (int i = 1; i <= N; i ++) {
            cin >> gridLine;
            for (int j = 1; j <= N; j ++) {
                if (gridLine[j - 1] == '*') {
                    x[++K] = i;
                    y[K] = j;
                }
            }
        }
        for (int i = 1; i <= K; i ++) {
            nearest[i].clear();
            for (int j = 1; j <= K; j ++) {
                if (i != j) {
                    nearest[i].insert(neighbor(abs(x[i] - x[j]) + abs(y[i] - y[j]), j));
                    if ((int)nearest[i].size() > C) {
                        nearest[i].erase(--nearest[i].end());
                    }
                }
            }
        }
        int result = 1 << 30;
        for (int i = 1; i <= K; i ++) {
            int now = i;
            int sum = 0;
            usedID[1] = i;
            alreadyUsed[i] = 1;
            for (int j = 1; j < C && sum < result; j ++) {
                for (auto k : nearest[now]) {
                    if (!alreadyUsed[k.id]) {
                        sum += k.d;
                        now = k.id;
                        usedID[j + 1] = k.id;
                        alreadyUsed[k.id] = 1;
                        break;
                    }
                }
            }
            for (int j = 1; j <= C; j ++) {
                alreadyUsed[usedID[j]] = 0;
            }
            result = min(result, sum);
        }
        printf("%d\n", result);
    }
    
    return 0;
}


