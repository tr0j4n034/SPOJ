//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

const int MAX = 1000005;

struct node {
    long long sum = -1;
    int leftChildID = 0;
    int rightChildID = 0;
    node () {
        
    }
    node (long long sum, int l, int r)
    :sum(sum), leftChildID(l), rightChildID(r) {
        
    }
};

long long get(node p) {
    return p.sum == -1 ? 0 : p.sum;
}

node pool[MAX << 4];
int offset = 0;

void add(node &root, int low, int high, int position, int value) {
    //if (!root.active) root = pool[++offset];
    if (low == high) {
        root.sum += value;
        return;
    }
    int middle = (low + high) >> 1;
    if (position <= middle) {
        if (!root.leftChildID) {
            root.leftChildID = ++offset;
            pool[root.leftChildID].sum = 0;
        }
        add(pool[root.leftChildID], low, middle, position, value);
    }
    else {
        if (!root.rightChildID) {
            root.rightChildID = ++offset;
            pool[root.rightChildID].sum = 0;
        }
        add(pool[root.rightChildID], middle + 1, high, position, value);
    }
    root.sum = get(pool[root.leftChildID]) + get(pool[root.rightChildID]);
}

long long get(node &root, int low, int high, int l, int r) {
    if (root.sum == -1) return 0;
    if (low > r || high < l) return 0;
    if (low >= l && high <= r) return root.sum;
    int middle = (low + high) >> 1;
    return get(pool[root.leftChildID], low, middle, l, r)
    + get(pool[root.rightChildID], middle + 1, high, l, r);
}

template<class T>
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
template<class T> void fastPrint(T &n){
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

int N, Q;
int p[MAX], lp[MAX];
node roots[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i; j < MAX; j += i) {
            p[j] ++;
            lp[j] = i;
        }
    }
    
    //scanf("%d%d", &N, &Q);
    fastInput(N);
    fastInput(Q);
    
    for (int i = 1; i < MAX; i ++) {
        if (p[i] == 1) {
            roots[i] = pool[++offset];
            roots[i].sum = 0;
        }
    }
    for (int i = 1; i <= N; i ++) {
        int x, y;
        //scanf("%d", &x);
        fastInput(x);
        y = x;
        while (x > 1) {
            int d = 1, v = lp[x];
            while (x % v == 0) {
                x /= v;
                d *= v;
            }
            add(roots[d], 1, N, i, y);
        }
    }
    while (Q --) {
        int l, r, p;
        //scanf("%d%d%d", &l, &r, &p);
        fastInput(l);
        fastInput(r);
        fastInput(p);
        long long result = 0;
        for (int i = p; i < MAX; ) {
            result += get(roots[i], 1, N, l, r) * (i - 1) / i;
            if (i > (MAX - 1) / p) break;
            else i *= p;
        }
        //printf("%lld\n", result);
        fastPrint(result);
    }
    
    return 0;
}
