//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/26/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * N^3 * log(L)) solution using matrix exponentiation.
 Be careful when analyzing how transformation matrix is generated.
 */

#include <iostream>
#include <cassert>

using namespace std;

const int MAX = 35;
//const int MODULO = 1000000000;
int MODULO;

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

int T, N, K, L;
int b[MAX], c[MAX];

int main() {
    cin >> T;
    for (int cases = 0; cases < T; cases ++) {
        cin >> N >> K >> L;
        MODULO = 1;
        for (int i = 0; i < K; i ++) {
            MODULO *= 10;
        }
        matrix transformation;
        transformation.rowSize = N;
        transformation.columnSize = N;
        for (int i = 2; i <= N; i ++) {
            transformation.data[i - 1][i] = 1;
        }
        for (int i = 1; i <= N; i ++) {
            transformation.data[N][i] = 1;
        }
        matrix identity;
        identity.rowSize = N;
        identity.columnSize = 1;
        for (int i = 1; i <= N; i ++) {
            identity.data[i][1] = i - 1;
        }
        matrix result = transformation.power(L) * identity;
        cout << result.data[1][1] << endl;
    }
    
    return 0;
}
