//
//  main.cpp
//  practice
//
//  Created by Mahmud on 20/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

// slow O(T * (N + Q) * log(N)) solution using implicit segment trees

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int S = 1 << 18;

struct node{
    int value;
    node *leftChild;
    node *rightChild;
    node () {}
    node(int value):
    value(value), leftChild(NULL), rightChild(NULL) {}
};
typedef node* pnode;

int getValue(pnode &p) {
    return p ? p->value : 0;
}
pnode add(pnode &p, int low, int high, int position, int v) {
    if (!p) {
        p = new node(0);
    } if (low == high) {
        pnode result = new node(p->value + v);
        return result;
    }
    int middle = (low + high) >> 1;
    pnode result = new node(0);
    if (position <= middle) {
        result->leftChild = add(p->leftChild, low, middle, position, v);
        result->rightChild = p->rightChild;
    } else {
        result->leftChild = p->leftChild;
        result->rightChild = add(p->rightChild, middle + 1, high, position, v);
    }
    result->value = getValue(result->leftChild) + getValue(result->rightChild);
    return result;
}
int get(pnode &p, int low, int high, int l, int r) {
    if (!p) {
        return 0;
    } else if (low > r || high < l) {
        return 0;
    } else if (low >= l && high <= r) {
        return p->value;
    }
    int middle = (low + high) >> 1;
    return get(p->leftChild, low, middle, l, r)
    + get(p->rightChild, middle + 1, high, l, r);
}

int T, N, Q;
int data[S], nextTo[S], last[S];
pnode roots[S];

template <class T>
void fastInput(T &N) {
    char ch;
    int sign = 1;
    N = 0;
    while ((ch = getchar_unlocked()) && ch == ' ') {};
    if (ch == '-') sign = -1;
    else if (isdigit(ch)) N = ch - '0';
    while ((ch = getchar_unlocked()) && isdigit(ch)) {
        N = (N << 1) + (N << 3) + ch - '0';
    }
    if (sign == -1) N = ~N + 1;
}
template<class T> void fastPrint(T n){
    if(n == 0){
        puts("0");
        return;
    }
    char buffer[256];
    int ptr = 0, sign = 1;
    
    if(n < 0){
        sign = -1;
        n *= -1;
    }
    while(n > 0){
        buffer[ptr ++] = (char)(n % 10 + '0');
        n /= 10;
    }
    if(sign == -1)
        putchar_unlocked('-');
    for(int i = ptr - 1; i >= 0; i --)
        putchar_unlocked(buffer[i]);
    putchar_unlocked('\n');
}

int main() {
    //scanf("%d", &T);
    fastInput(T);
    for (int c = 0; c < T; c ++) {
        //scanf("%d%d", &N, &Q);
        fastInput(N);
        fastInput(Q);
        for (int i = 1; i <= N; i ++) {
            //scanf("%d", &data[i]);
            fastInput(data[i]);
        }
        vector<int> values = vector<int>(data + 1, data + N + 1);
        sort(values.begin(), values.end());
        for (int i = 1; i <= N; i ++) {
            data[i] = (int)(lower_bound(values.begin(), values.end(), data[i]) - values.begin()) + 1;
        }
        for (int i = 1; i <= N + 1; i ++) {
            roots[i] = NULL;
            last[i] = N + 1;
        }
        for (int i = N; i > 0; i --) {
            nextTo[i] = last[data[i]];
            last[data[i]] = i;
        }
        for (int i = 1; i <= N; i ++) {
            roots[i] = add(roots[i - 1], 1, N + 1, nextTo[i], +1);
        }
        printf("Case %d:\n", c + 1);
        while (Q --) {
            int l, r;
            //scanf("%d%d", &l, &r);
            fastInput(l);
            fastInput(r);
            //printf("%d\n", get(roots[r], 1, N + 1, r + 1, N + 1) - get(roots[l - 1], 1, N + 1, r + 1, N + 1));
            fastPrint(get(roots[r], 1, N + 1, r + 1, N + 1) - get(roots[l - 1], 1, N + 1, r + 1, N + 1));
        }
    }
    
    return 0;
}

