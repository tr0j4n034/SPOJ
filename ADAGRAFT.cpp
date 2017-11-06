//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/06/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N * log(N)) solution using persistent segment trees...
 Instead of counting the number of unique elements in every subtree, let's
 make a dfs and flatten the tree to an array (it can be done by saving coming in and out times in dfs call)
 Now, the number of different elements in the subtree of node x is equal to the number of different elements
 in [in(x)..out[x]] subarray.
 This part of the problem is a very popular problem and can be efficiently solved by persistent segment trees.
 HINT: Keep track of the next occurences of every element in new array.
 And build the persistent segment trees on this nextOccurence array.
 In order to count the number of unique elements in a particular range [l, r], we just need to count the number of
 elements which are greater than r.
 This can be done by calculating get(roots[r], r + 1, infinity) - get(roots[l - 1], r + 1, infinity).
 
 Fast input and coordinate compression technique have been used to boost performance,
 the latter one omits extra log(N) factor...
 
 Note: This problem can be solved by using MO's algorithm in O(N * sqrt(N)) time as well.
 Another solution is O(N * log^2(N)) by 'merging smaller sets to larger ones' technique
 which is heavily based on STL sets.
 
 If you have any feedback about this and other mentioned solutions, drop me and e-mail. (tr0j4n034@gmail.com)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 400005;
const int MODULO = 1000000007;

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

struct node {
    int sum;
    node *l;
    node *r;
    
    node () {
        
    }
};
typedef node* pnode;

int get(pnode root) {
    return root ? root->sum : 0;
}
pnode initialize(int value) {
    pnode root = (pnode)malloc(sizeof(node));
    root->sum = value;
    root->l = NULL;
    root->r = NULL;
    return root;
}

node* add(pnode &root, int low, int high, int position, int value) {
    if (!root) {
        root = initialize(0);
    }
    if (low == high) {
        pnode result = initialize(root->sum + value);
        return result;
    }
    int middle = (low + high) >> 1;
    pnode result = initialize(0);
    if (position <= middle) {
        result->l = add(root->l, low, middle, position, value);
        result->r = root->r;
    }
    else {
        result->l = root->l;
        result->r = add(root->r, middle + 1, high, position, value);
    }
    result->sum = get(result->l) + get(result->r);
    return result;
}
int get(pnode &root, int low, int high, int l, int r) {
    if (!root) {
        return 0;
    }
    if (low > r || high < l) {
        return 0;
    }
    if (low >= l && high <= r) {
        return root->sum;
    }
    int middle = (low + high) >> 1;
    return get(root->l, low, middle, l, r)
    + get(root->r, middle + 1, high, l, r);
}

pnode roots[MAX];

int N;
int timer;
int data[MAX];
int flattenedData[MAX];
int in[MAX], out[MAX], who[MAX];
int nextOccurence[MAX], lastOccurence[MAX];
vector<int> edges[MAX];

void dfs(int node) {
    in[node] = ++timer;
    who[timer] = node;
    for (int neighbor : edges[node]) {
        dfs(neighbor);
    }
    out[node] = timer;
}

int main() {
    fastInput(N);
    for (int i = 1; i < N; i ++) {
        int parent;
        fastInput(parent);
        edges[parent].push_back(i);
    }
    for (int i = 0; i < N; i ++) {
        fastInput(data[i]);
    }
    dfs(0);
    
    vector<int> values = vector<int>(data, data + N);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0; i < N; i ++) {
        int compressedValue = (int)(lower_bound(values.begin(), values.end(), data[i]) - values.begin()) + 1;
        data[i] = compressedValue;
    }
    for (int i = 1; i <= timer; i ++) {
        flattenedData[i] = data[who[i]];
    }
    
    int valueCount = (int)values.size();
    int INFINITY = timer + 1;
    for (int i = timer; i > 0; i --) {
        if (!lastOccurence[flattenedData[i]]) {
            nextOccurence[i] = INFINITY;
        }
        else {
            nextOccurence[i] = lastOccurence[flattenedData[i]];
        }
        lastOccurence[flattenedData[i]] = i;
    }
    roots[0] = initialize(0);
    for (int i = 1; i <= timer; i ++) {
        roots[i] = add(roots[i - 1], 1, timer + 1, nextOccurence[i], 1);
    }
    
    int answer = 1;
    for (int i = 0; i < N; i ++) {
        int nodeValue = get(roots[out[i]], 1, timer + 1, out[i] + 1, timer + 1)
        - get(roots[in[i] - 1], 1, timer + 1, out[i] + 1, timer + 1);
        answer = 1LL * answer * nodeValue % MODULO;
    }
    cout << answer << endl;
    
    return 0;
}

