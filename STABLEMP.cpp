//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/31/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 505;

int T, N;
int menPreferences[MAX][MAX], womenID[MAX][MAX]; // men
int womenPreferences[MAX][MAX], menID[MAX][MAX]; // women
int menPreferencePointer[MAX]; // men
vector<int> calledBy[MAX]; // women

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            int id;
            scanf("%d", &id);
            for (int j = 1; j <= N; j ++) {
                scanf("%d", &womenPreferences[id][j]);
            }
        }
        for (int i = 1; i <= N; i ++) {
            int id;
            scanf("%d", &id);
            for (int j = 1; j <= N; j ++) {
                scanf("%d", &menPreferences[id][j]);
            }
        }
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= N; j ++) {
                womenID[i][menPreferences[i][j]] = j;
                menID[i][womenPreferences[i][j]] = j;
            }
        }
        for (int i = 1; i <= N; i ++) {
            menPreferencePointer[i] = 1;
            calledBy[i].clear();
        }
        for ( ; ; ) { // no more than N * N + 1 times actually...
            for (int i = 1; i <= N; i ++) { // men propose
                while (menPreferences[i][menPreferencePointer[i]] == 0) {
                    menPreferencePointer[i] ++;
                }
                int girlToPropose = menPreferences[i][menPreferencePointer[i]];
                calledBy[girlToPropose].push_back(i);
            }
            bool anyThingDone = false;
            for (int i = 1; i <= N; i ++) { // women take decisions
                if ((int)calledBy[i].size() < 2) {
                    calledBy[i].clear();
                    continue;
                }
                anyThingDone = true;
                int bestManCandidate = calledBy[i].front();
                for (auto man: calledBy[i]) {
                    if (menID[i][man] < menID[i][bestManCandidate]) {
                        bestManCandidate = man;
                    }
                }
                for (auto man: calledBy[i]) { // men take decisions
                    if (man != bestManCandidate) {
                        menPreferences[man][womenID[man][i]] = 0;
                    }
                }
                calledBy[i].clear();
            }
            if (!anyThingDone) {
                for (int i = 1; i <= N; i ++) {
                    cout << i << " " << menPreferences[i][menPreferencePointer[i]] << endl;
                }
                break;
            }
        }
    }
    
    return 0;
}
