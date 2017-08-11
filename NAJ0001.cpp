//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/11/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 A strict O(N * max(V) + M) solution
 Queries are grouped according to their "V" values
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef pair<pair<int, int>, int> query;

const int MAX = 200005;
const int SIZE = 1005;

int T, N, M;
int data[MAX];
long long prefix[MAX], output[MAX];
vector<query> queries[SIZE];

template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int main(int argc, const char * argv[]) {
    fastInput(T);
    for (int c = 0; c < T; c ++) {
        fastInput(N);
        fastInput(M);
        for (int i = 1; i <= N; i ++) {
            fastInput(data[i]);
        }
        for (int i = 1; i < SIZE; i ++) {
            queries[i].clear();
        }
        for (int i = 0; i < M; i ++) {
            int v, x, y;
            fastInput(v);
            fastInput(x);
            fastInput(y);
            queries[v].push_back(make_pair(make_pair(x, y), i));
        }
        for (int i = 1; i < SIZE; i ++) {
            if (queries[i].empty()) {
                continue;
            }
            sort(queries[i].begin(), queries[i].end(), [&](const query a, const query b){
                return a.first.second < b.first.second;
            });
            int ptr = 0;
            int lengthOfBlock = (int)queries[i].size();
            for (int j = 1; j <= N; j ++) {
                prefix[j] = prefix[j - 1] + (data[j] % i == 0 ? data[j] : 0);
                while (ptr < lengthOfBlock && queries[i][ptr].first.second == j) {
                    output[queries[i][ptr].second] =
                    prefix[j] - prefix[queries[i][ptr].first.first - 1];
                    ptr ++;
                }
            }
        }
        if (c > 0) {
            putchar_unlocked('\n');
        }
        printf("Case #%d\n", c + 1);
        for (int i = 0; i < M; i ++) {
            printf("%lld\n", output[i]);
        }
    }
    
    return 0;
}
