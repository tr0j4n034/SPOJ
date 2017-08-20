//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/20/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10005;

int T, N;
int data;
int listSize;
int primes[MAX], counts[MAX];
char type[5];
vector<int> divisors[MAX];
set<int> active[MAX];

void add (int data) {
    listSize ++;
    for (int i : divisors[data]) {
        counts[i] ++;
        if (counts[i] > 1) {
            active[counts[i] - 1].erase(i);
        }
        active[counts[i]].insert(i);
    }
}
void remove (int data) {
    listSize --;
    for (int i : divisors[data]) {
        counts[i] --;
        if (counts[i] > 0) {
            active[counts[i]].insert(i);
        }
        active[counts[i] + 1].erase(i);
    }
}

int main(int argc, const char * argv[]) {
    for (int i = 2; i < MAX; i ++) {
        if (!primes[i]) {
            for (int j = i + i; j < MAX; j += i) {
                primes[j] = 1;
            }
        }
        else {
            for (int j = i; j < MAX; j += i) {
                divisors[j].push_back(i);
            }
        }
    }
    scanf("%d", &T);
    while (T --) {
        listSize = 0;
        fill(counts, counts + MAX, 0);
        for (int i = 1; i < MAX; i ++) {
            active[i].clear();
        }
        scanf("%d", &N);
        for (int _ = 0; _ < N; _ ++) {
            scanf(" %s", type);
            if (type[0] == 'U') {
                scanf(" %s%d", type, &data);
                if (type[0] == 'A') {
                    add(data);
                }
                else {
                    remove(data);
                }
            }
            else {
                if (listSize == 0) {
                    puts("-1");
                }
                else {
                    putchar_unlocked('1');
                    for (int i : active[listSize]) {
                        printf(" %d", i);
                    }
                    putchar_unlocked('\n');
                }
            }
        }
    }
    
    return 0;
}
