//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/23/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * K^3 * log(N)) solution by matrix exponentation
 I strongly recommend you to learn how to build transformation by from the following resource.
 http://fusharblog.com/solving-linear-recurrence-for-programming-contest/
 */

#include <iostream>
#include <cassert>

using namespace std;

const int MAX = 15;
const int MODULO = 1000000000;

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
                    result.data[i][j] = (result.data[i][j] + 1LL * data[i][k] * other.data[k][j] % MODULO) % MODULO;
                }
            }
        }
        result.rowSize = rowSize;
        result.columnSize = other.columnSize;
        return result;
    }
    matrix power(int e) {
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

int T, N, K;
int b[MAX], c[MAX];

int main() {
    cin >> T;
    for (int cases = 0; cases < T; cases ++) {
        cin >> K;
        for (int i = 1; i <= K; i ++) {
            cin >> b[i];
        }
        for (int i = 1; i <= K; i ++) {
            cin >> c[i];
        }
        cin >> N;
        if (N <= K) {
            cout << b[N] << endl;
            continue;
        }
        
        matrix t, I;
        t.rowSize = K;
        t.columnSize = K;
        for (int i = 2; i <= K; i ++) {
            t.data[i - 1][i] = 1;
        }
        for (int i = 1; i <= K; i ++) {
            t.data[K][i] = c[K - i + 1];
        }
        I.rowSize = K;
        I.columnSize = 1;
        for (int i = 1; i <= K; i ++) {
            I.data[i][1] = b[i];
        }
        matrix result = t.power(N - K) * I;
        cout << result.data[K][1] << endl;
    }
    
    return 0;
}
