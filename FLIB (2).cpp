//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/26/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 The most stupid time limit ever.
 I sorted input queries, so that we do not need to make mass calculation every time.
 */


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 5;
int MODULO = 1000000007;

void add(int &a, int b) {
    a += b;
    if (a >= MODULO) {
        a -= MODULO;
    }
}
struct matrix{
    int rowSize = MAX - 1;
    int columnSize = MAX - 1;
    int data[MAX][MAX];
    matrix () {
        for (int i = 1; i <= rowSize; i ++) {
            for (int j = 1; j <= columnSize; j ++) {
                data[i][j] = 0;
            }
        }
    }
    matrix operator * (const matrix other) const{
        assert(columnSize == other.rowSize);
        matrix result = matrix();
        for (int i = 1; i <= rowSize; i ++) {
            for (int j = 1; j <= other.columnSize; j ++) {
                for (int k = 1; k <= columnSize; k ++) {
                    add(result.data[i][j], 1LL * data[i][k] * other.data[k][j] % MODULO);
                }
            }
        }
        result.rowSize = rowSize;
        result.columnSize = other.columnSize;
        return result;
    }
    matrix power(long long e) {
        if (e == 1) {
            return *this;
        }
        if (e & 1) {
            return (*this) * power(e - 1);
        }
        matrix half = power(e >> 1);
        return half * half;
    }
};

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

int T;
long long N;
int output[40004];
pair<long long, int> queries[40004];

int main() {
    matrix identity;
    identity.rowSize = 3;
    identity.columnSize = 1;
    identity.data[1][1] = 0;
    identity.data[2][1] = 2;
    identity.data[3][1] = 3;
    matrix transformation;
    transformation.rowSize = 3;
    transformation.columnSize = 3;
    transformation.data[1][1] = 1;
    transformation.data[1][2] = 1;
    transformation.data[2][2] = 2;
    transformation.data[2][3] = 3;
    transformation.data[3][2] = 3;
    transformation.data[3][3] = 5;
    
    scanf("%d", &T);
    for (int cases = 0; cases < T; cases ++) {
        //scanf("%lld", &N);
        fastInput(N);
        queries[cases] = make_pair(N, cases);
    }
    sort(queries, queries + T);
    matrix result = transformation.power(queries[0].first);
    for (int i = 0; i < T; i ++) {
        if (i > 0 && queries[i].first != queries[i - 1].first) {
            result = result * transformation.power(queries[i].first - queries[i - 1].first);
        }
        output[queries[i].second] = (result * identity).data[1][1];
    }
    for (int i = 0; i < T; i ++) {
        fastPrint(output[i]);
    }
    
    return 0;
}
