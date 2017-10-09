//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/9/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 A solution based on binary trie
 Think this way: a[l] ^ a[l + 1] ^ a[l + 2] ^ ... ^ a[r] = prefixXor[r] ^ prefix[l - 1]
 Now problem is reduced to find how many previous prefixes satisfy the condition
 It can be done traversing the binary trie from greatest bit to lowest (20...0)
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100005;
const int MAX_BITS = 20;
/*
 x ^ pref[now] < K
 
 */

struct node {
    int sum;
    node* l;
    node* r;
    node () {
        
    }
};
typedef node* pnode;

int get(pnode &p) {
    return p ? p->sum : 0;
}
pnode initialize(int value) {
    pnode p = (pnode)malloc(sizeof(node));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void add(pnode &p, int value) {
    pnode current = p;
    for (int i = MAX_BITS; i >= 0; i --) {
        int bit = (value >> i) & 1;
        if (!bit) {
            if (!current->l) {
                current->l = initialize(0);
            }
            current = current->l;
        }
        else {
            if (!current->r) {
                current->r = initialize(0);
            }
            current = current->r;
        }
        current->sum ++;
    }
}
int get(pnode &p, int prefix, int value) {
    int result = 0;
    pnode current = p;
    for (int i = MAX_BITS; i >= 0; i --) {
        if (!current) {
            break;
        }
        int prefixBit = (prefix >> i) & 1;
        int bit = (value >> i) & 1;
        if (prefixBit == bit) {
            if (prefixBit == 1) {
                result += get(current->r);
            }
            current = current->l;
        }
        else {
            if (prefixBit == 0) {
                result += get(current->l);
            }
            current = current->r;
        }
    }
    return result;
}

int T, N, K;
int data[MAX], prefix[MAX];
pnode root;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T --) {
        cin >> N >> K;
        for (int i = 1; i <= N; i ++) {
            cin >> data[i];
        }
        root = initialize(0);
        add(root, 0);
        long long result = 0;
        for (int i = 1; i <= N; i ++) {
            prefix[i] = prefix[i - 1] ^ data[i];
            result += get(root, prefix[i], K);
            add(root, prefix[i]);
        }
        cout << result << endl;
    }
    
    return 0;
}
