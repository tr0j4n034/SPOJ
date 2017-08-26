//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/26/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 A solution containing pruning
 If every number has even frequency in a range, then xor of all numbers in the range
 must be equal to 0. Prefix table is used to check that condition.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MAX = 100005;
const int MAGIC = 25;

int T, N, Q;
long long data[MAX], prefix[MAX];
map<long long, vector<int>> occurrences;

void rebuild () {
    for (int i = 1; i <= N; i ++) {
        prefix[i] = prefix[i - 1] ^ data[i];
    }
    occurrences.clear();
    for (int i = 1; i <= N; i ++) {
        occurrences[data[i]].push_back(i);
    }
}

int main(int argc, const char * argv[]) {
    srand(unsigned(time(NULL)));
    
    scanf("%d", &T);
    for (int c = 0; c < T; c ++) {
        scanf("%d%d", &N, &Q);
        for (int i = 1; i <= N; i ++) {
            scanf("%lld", &data[i]);
        }
        rebuild();
        printf("Case %d:\n", c + 1);
        while (Q --) {
            int type;
            scanf("%d", &type);
            if (type == 0) {
                int position, value;
                scanf("%d%d", &position, &value);
                data[position] += value;
                rebuild();
            }
            else if (type == 1) {
                int l, r, value;
                scanf("%d%d%d", &l, &r, &value);
                for (int i = l; i <= r; i ++) {
                    data[i] = value;
                }
                rebuild();
            }
            else {
                int l, r;
                scanf("%d%d", &l, &r);
                bool failed = false;
                if ((r - l + 1) & 1) {
                    failed = true;
                }
                if (!failed) {
                    long long g = prefix[r] ^ prefix[l - 1];
                    if (g != 0) {
                        failed = true;
                    }
                }
                if (!failed) {
                    for (int i = 0; i < MAGIC; i ++) {
                        int id = l + 1LL * rand() * rand() % (r - l + 1);
                        int cnt = (int)(
                                        upper_bound(occurrences[data[id]].begin(), occurrences[data[id]].end(), r)
                                        - lower_bound(occurrences[data[id]].begin(), occurrences[data[id]].end(), l));
                        if (cnt & 1) {
                            failed = true;
                            break;
                        }
                    }
                }
                if (failed) {
                    puts("No");
                }
                else {
                    puts("Yes");
                }
            }
        }
    }
    
    return 0;
}
