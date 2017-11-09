//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/09/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * log(N)) solution using matrix exponentiation
 This is how transformation matrix has been constructed:
 
 | F(n - 4) |    | 0 1 0 0 0 |   | F(n - 3) |
 | F(n - 3) |    | 0 0 1 0 0 |   | F(n - 2) |
 | F(n - 2) |  * | 0 0 0 1 0 | = | F(n - 1) |
 | F(n - 1) |    | 0 0 0 0 1 |   |   F(n)   |
 |   F(n)   |    | 1 5 0 2 1 |   | F(n + 1) |
 
 */

#include <iostream>
#include <cassert>

using namespace std;

const int MAX = 6;
const int MODULO = 1000000007;

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

int T;
long long N;
int coefficients[MAX];

int main() {
    matrix transformation;
    transformation.rowSize = 5;
    transformation.columnSize = 5;
    for (int i = 2; i <= 5; i ++) {
        transformation.data[i - 1][i] = 1;
    }
    transformation.data[5][1] = 1;
    transformation.data[5][2] = 5;
    transformation.data[5][3] = 0;
    transformation.data[5][4] = 2;
    transformation.data[5][5] = 1;
    
    cin >> T;
    for (int cases = 0; cases < T; cases ++) {
        for (int i = 0; i < 5; i ++) {
            cin >> coefficients[i];
        }
        cin >> N;
        if (N < 5) {
            cout << coefficients[N] << endl;
            continue;
        }
        matrix identity;
        identity.rowSize = 5;
        identity.columnSize = 1;
        for (int i = 1; i <= 5; i ++) {
            identity.data[i][1] = coefficients[i - 1];
        }
        matrix result = transformation.power(N) * identity;
        cout << result.data[1][1] << endl;
    }
    
    return 0;
}
