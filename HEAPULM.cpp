//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/01/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * log(N)) solution based on standard tree building technique
 After sorting data on the labels, we need to recursively build the tree:
  - build left subtree
  - add current node
  - build right subtree
 In order to find the maximum priority each time for any range, a number of data structures are
  available to retrieve the result in O(log(N)) or O(1)...
 */

//#pragma comment(linker, "/stack:200000000")

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>

using namespace std;

const int MAX = 100005;

struct SparseTable {
    //int *data;
    //int** table; // indices of maximum elements
    int data[MAX];
    int table[18][MAX];
    SparseTable () {
        
    }
    SparseTable(int *_data, int N = 0) {
        //data = _data;
        for (int i = 1; i <= N; i ++) data[i] = _data[i];
        int d = 31 - __builtin_clz(N);
        //table = (int**)calloc(d + 1, sizeof(int));
        //for (int i = 0; i <= d; i ++) table[i] = (int *)calloc(N + 1, sizeof(int));
        for (int i = 0; i <= d; i ++) {
            for (int j = 1; j + (1 << i) - 1 <= N; j ++) {
                if (i == 0) table[i][j] = j;
                else {
                    if (data[table[i - 1][j]] > data[table[i - 1][j + (1 << (i - 1))]]) {
                        table[i][j] = table[i - 1][j];
                    } else {
                        table[i][j] = table[i - 1][j + (1 << (i - 1))];
                    }
                }
            }
        }
    }
    int query(int low, int high) {
        int delta = 31 - __builtin_clz(high - low + 1);
        if (data[table[delta][low]] > data[table[delta][high - (1 << delta) + 1]]) {
            return table[delta][low];
        } else {
            return table[delta][high - (1 << delta) + 1];
        }
    }
};

int N;
char ch;
int priorities[MAX];
string labels[MAX];
SparseTable st;

int pr = 0;
string data, lb = "";

int indices[MAX];
int tempPriorities[MAX];
string tempLabels[MAX];

void print(int low, int high) {
    if (low > high) return;
    int root = st.query(low, high);
    if (root != low) {
        cout << "(";
        print(low, root - 1);
        cout << ")";
    }
    cout << labels[root] << "/" << priorities[root];
    if (root != high) {
        cout << "(";
        print(root + 1, high);
        cout << ")";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (cin >> N) {
        if (N == 0) break;
        for (int i = 1; i <= N; i ++) {
            cin >> data;
            lb = "";
            pr = 0;
            for (int j = 0; j < (int)data.size(); j ++) {
                if (data[j] == '/') continue;
                else if (isdigit(data[j])) pr = (pr << 3) + (pr << 1) + data[j] - '0';
                else lb += data[j];
            }
            labels[i] = lb;
            priorities[i] = pr;
            assert(pr >= 0);
        }
        
        iota(indices + 1, indices + N + 1, 1);
        sort(indices + 1, indices + N + 1, [](int a, int b) {
            return labels[a] < labels[b];
        });
        for (int i = 1; i <= N; i ++) {
            tempLabels[i] = labels[indices[i]];
            tempPriorities[i] = priorities[indices[i]];
        }
        for (int i = 1; i <= N; i ++) {
            labels[i] = tempLabels[i];
            priorities[i] = tempPriorities[i];
        }
        st = SparseTable(priorities, N);
        
        cout << "(";
        print(1, N);
        cout << ")";
        cout << endl;
    }
    
    return 0;
}
