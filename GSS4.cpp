//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/12/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * (N + Q) * log(N)) solution based on Fenwick trees
 Just think how many times a number can be reduced to its square root
 until it reaches 1. Then the only thing we need to take care of is ones in the array.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>


using namespace std;

const int MAX = 100005;

int N, Q;
int cases;
int type, x, y;
long long data[MAX];
long long ftree[MAX];

void add(int position, long long value) {
    for ( ; position <= N; position += (position & -position)) {
        ftree[position] += value;
    }
}
long long get(int position) {
    long long result = 0;
    for ( ; position > 0; position -= (position & -position)) {
        result += ftree[position];
    }
    return result;
}

int main() {
    while (scanf("%d", &N) != EOF) {
        ++cases;
        for (int i = 1; i <= N; i ++) {
            scanf("%lld", &data[i]);
        }
        set<int> active;
        for (int i = 1; i <= N; i ++) {
            if (data[i] > 1) {
                active.insert(i);
            }
        }
        fill(ftree, ftree + N + 1, 0LL);
        for (int i = 1; i <= N; i ++) {
            add(i, data[i]);
        }
        scanf("%d", &Q);
        //if (cases > 0) {
        //    puts("");
        //}
        printf("Case #%d:\n", cases);
        while (Q --) {
            scanf("%d%d%d", &type, &x, &y);
            if (x > y) {
                swap(x, y);
            }
            if (type == 0) {
                set<int> :: iterator it = active.lower_bound(x);
                set<int> toDelete;
                while (it != active.end() && *it <= y) {
                    add(*it, -data[*it]);
                    data[*it] = (long long)(sqrtl(1.0 * data[*it]));
                    add(*it, data[*it]);
                    if (data[*it] == 1) {
                        toDelete.insert(*it);
                    }
                    it ++;
                }
                for (int i : toDelete) {
                    active.erase(i);
                }
            }
            else {
                printf("%lld\n", get(y) - get(x - 1));
            }
        }
        puts("");
    }
    
    return 0;
}
