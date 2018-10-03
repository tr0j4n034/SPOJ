//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(T * N * MAX_BITS)) solution using 'binary trie's
 MAX_BITS is 31 (0..30) since the answer can not have a larger set bit.
 Let's add all prefix xors of the input array one by one:
  During each iteration i we need to get the maximum suffix ending at i.
  Basically, we need to find such j that (a[j] ^ a[j + 1] ^ ... ^ a[i]) ^ X is maximum.
  Surely, if we do the process for each i, then answer is found.
  It is obvious that
        (a[j] ^ a[j + 1] ^ ... ^ a[i]) ^ X =
            = (pref[i] ^ pref[j - 1]) ^ X =
            (pref[i] ^ X) ^ pref[j - 1]
  So we just need to make a traversal in out trie to find best match for
    the value (pref[i] ^ X). And it is classic problem which is solved using tries.
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int S = 1 << 18;
const int MAX_BIT = 30;

struct node{
    int value;
    int leftChildID;
    int rightChildID;
    node() {
        
    }
    node(int v, int l, int r):
    value(v), leftChildID(l), rightChildID(r) {
        
    }
};

node pool[S];
int offset = 0;

int allocate(int value) {
    pool[++offset].value = value;
    pool[offset].leftChildID = -1;
    pool[offset].rightChildID = -1;
    return offset;
}
void add(int value) {
    int id = 0;
    for (int i = MAX_BIT; i >= 0; i --) {
        int bit = (value >> i) & 1;
        if (!bit) {
            if (pool[id].leftChildID == -1) {
                pool[id].leftChildID = allocate(0);
            }
            id = pool[id].leftChildID;
        } else {
            if (pool[id].rightChildID == -1) {
                pool[id].rightChildID = allocate(0);
            }
            id = pool[id].rightChildID;
        }
        pool[id].value = 1;
    }
}
int getMatch(int x) {
    int id = 0;
    int result = 0;
    for (int i = MAX_BIT; i >= 0; i --) {
        if (pool[id].value == 0) {
            break;
        }
        int bit = (x >> i) & 1;
        if (!bit) {
            if (pool[id].rightChildID != -1) {
                result |= 1 << i;
                id = pool[id].rightChildID;
            } else {
                id = pool[id].leftChildID;
            }
        } else {
            if (pool[id].leftChildID != -1) {
                id = pool[id].leftChildID;
            } else {
                result |= 1 << i;
                id = pool[id].rightChildID;
            }
        }
    }
    return result;
}

int N, T, X;
int data[S];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &X);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &data[i]);
        } for (int i = 0; i < S; i ++) {
            pool[i] = node(0, -1, -1);
        }
        pool[0].value = 1;
        offset = 0;
        add(0);
        int prefix = 0, bestResult = data[1];
        for (int i = 1; i <= N; i ++) {
            prefix ^= data[i];
            add(prefix);
            int current = prefix ^ getMatch(X ^ prefix);
            if ((X ^ current) > (X ^ bestResult)) {
                bestResult = current;
            }
        }
        printf("%d\n", bestResult);
    }
    
    return 0;
}
