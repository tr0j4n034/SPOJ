//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 The costs for converting a word to a magical word
 depends on the prefix matched and the length of the shortest matching word with that prefix.
 It can be done with tries.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

const int MAX = 10005;
const int ALPHABET = 26;

struct node {
    int active = MAX;
    node * link[ALPHABET];
    node () {
        
    }
};
typedef node* pnode;

pnode initializeNode () {
    pnode p = pnode(malloc(sizeof(node)));
    p->active = MAX;
    for (int i = 0; i < ALPHABET; i ++) {
        p->link[i] = NULL;
    }
    return p;
}

int T, A, B, K, N, M;
int length;
char ch;
pnode trie;
char word[MAX];

inline void readWord () {
    length = 0;
    while ((ch = getchar_unlocked()) != '\n') {
        word[++length] = ch - 'a';
    }
}

void addWord (char* word) {
    pnode root = trie;
    root->active = min(root->active, length);
    for (int i = 1; i <= length; i ++) {
        if (!root->link[word[i]]) {
            root->link[word[i]] = initializeNode();
        }
        root = root->link[word[i]];
        root->active = min(root->active, length);
    }
}
int getCost (char* word) {
    int l = 0;
    pnode root = trie;
    int best = length * A + root->active * B;
    for (int i = 1; i <= length; i ++) {
        if (!root->link[word[i]]) {
            break;
        }
        root = root->link[word[i]];
        l ++;
        best = min(best, (length - l) * A + (root->active - l) * B);
    }
    return best;
}

int main(int argc, const char * argv[]) {
    scanf("%d", &T);
    while (T --) {
        trie = initializeNode();
        scanf("%d%d%d%d%d", &A, &B, &K, &N, &M);
        getchar_unlocked();
        for (int i = 0; i < N; i ++) {
            readWord();
            addWord(word);
        }
        vector<int> costs;
        for (int i = 0; i < M; i ++) {
            readWord();
            costs.push_back(getCost(word));
        }
        sort(costs.begin(), costs.end());
        long long result = accumulate(costs.begin(), costs.begin() + K, 0LL);
        cout << result << endl;
    }
    
    return 0;
}
