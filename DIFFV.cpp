//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/27/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * N * K * log(K)) solution based on hashing
 Although there are plenty of ways to compare different vectors,
  hashing seems to be the simplest one. You can calculate any particular
   aggregate (min/max) rolling hash value for each of the vectors.
 Then check how many different hash values values exist...
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 305;
const int MAGIC = 113;

const int mods[] = {715225741, 1000000007};
const int muls[] = {43, 73};

//const int mods[] = {1000000000, 1000000000};
//const int muls[] = {10, 10};

int T, N, K;
int delta[MAX], last[MAX];
int prefixHash[2][MAX], powers[2][MAX];
vector<int> data, values;

template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    n = 0;
    while(ch = getchar_unlocked(), isspace(ch));
    if(ch == '-') sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int main() {
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < MAX; j ++) {
            if (j == 0) powers[i][j] = 1;
            else powers[i][j] = 1LL * powers[i][j - 1] * muls[i] % mods[i];
        }
    }
    fastInput(T);
    while (T --) {
        fastInput(N);
        fastInput(K);
        vector<pair<int, int>> identifiers(N);
        for (int i = 0; i < N; i ++) {
            data.resize(K);
            for (int j = 0; j < K; j ++) fastInput(data[j]);
            values = data;
            sort(values.begin(), values.end());
            values.erase(unique(values.begin(), values.end()), values.end());
            for (int j = 0; j < K; j ++) {
                data[j] = (int)(lower_bound(values.begin(), values.end(), data[j]) - values.begin());
            }
            vector<int> active = data;
            copy(active.begin(), active.end(), back_inserter(data));
            copy(active.begin(), active.end(), back_inserter(data));
            for (int j = 0; j < K; j ++) last[data[j]] = -1;
            for (int j = K + K + K - 1; j >= 0; j --) {
                if (last[data[j]] == -1) delta[j] = MAGIC;
                else delta[j] = last[data[j]] - j;
                last[data[j]] = j;
            }
            pair<int, int> currentHash = make_pair(0, 0);
            pair<int, int> biggestHash = make_pair(0, 0);
            for (int j = 0; j < K + K; j ++) {
                if (j == 0) {
                    prefixHash[0][j] = delta[j];
                    prefixHash[1][j] = delta[j];
                }
                else {
                    prefixHash[0][j] = (1LL * prefixHash[0][j - 1] * muls[0] % mods[0] + delta[j]) % mods[0];
                    prefixHash[1][j] = (1LL * prefixHash[1][j - 1] * muls[1] % mods[1] + delta[j]) % mods[1];
                }
                if (j >= K - 1) currentHash = make_pair(
                                                        (prefixHash[0][j] - 1LL * prefixHash[0][j - K] * powers[0][K] % mods[0] + mods[0]) % mods[0],
                                                        (prefixHash[1][j] - 1LL * prefixHash[1][j - K] * powers[1][K] % mods[1] + mods[1]) % mods[1]);
                if (j >= K - 1 && currentHash > biggestHash) biggestHash = currentHash;
            }
            identifiers[i] = biggestHash;
        }
        sort(identifiers.begin(), identifiers.end());
        identifiers.erase(unique(identifiers.begin(), identifiers.end()), identifiers.end());
        cout << (int)identifiers.size() << endl;
    }
    
    return 0;
}
