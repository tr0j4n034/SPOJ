//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/26/19.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
    O(N + Q * log(N)) solution via lazy segment trees
    Simply, mark the subarrays which need the update procedure.
    Inorder traversal of the tree will give the final result in linear time.
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, Q;

vector<int> stree, marked;

void push(int I, int low, int high) {
    if (marked[I]) {
        stree[I] = marked[I];
        if (low != high) {
            marked[I << 1] = marked[I];
            marked[I << 1 | 1] = marked[I];
        }
        marked[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r, int value) {
    push(I, low, high);
    if (low > r || high < l) return;
    if (low >= l && high <= r) {
        marked[I] = value;
        push(I, low, high);
        return;
    }
    int middle = (low + high) >> 1;
    update(I << 1, low, middle, l, r, value);
    update(I << 1 | 1, middle + 1, high, l, r, value);
}
void printTree(int I, int low, int high) {
    push(I, low, high);
    if (low == high) {
        printf("%d\n", stree[I]);
        return;
    }
    int middle = (low + high) >> 1;
    printTree(I << 1, low, middle);
    printTree(I << 1 | 1, middle + 1, high);
}

int main(int argc, const char* argv[]) {
    scanf("%d%d", &N, &Q);
    
    stree.resize(N << 2);
    marked.resize(N << 2);
    while (Q --) {
        int low, high, color;
        scanf("%d%d%d", &low, &high, &color);
        update(1, 1, N, low, high, color);
    }
    printTree(1, 1, N);
    
    return 0;
}

