//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/26/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

/*
 O(T * log(N)) solution using matrix exponentiation.
 Use a^(p - 1) % p = 1 property...
 */

#include <iostream>
#include <cassert>

using namespace std;

const int MAX = 35;
int MODULO = 1000000007;

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
int power(int a, int b, int modulo) {
    if (b == 0) {
        return 1 % modulo;
    }
    if (b & 1) {
        return 1LL * power(a, b - 1, modulo) * a % modulo;
    }
    int half = power(a, b >> 1, modulo);
    return 1LL * half * half % modulo;
}

int T;
long long N;

int main() {
    cin >> T;
    for (int cases = 0; cases < T; cases ++) {
        cin >> N;
        if (N == 0) {
            cout << 1 << endl;
            continue;
        }
        matrix transformation;
        transformation.rowSize = 2;
        transformation.columnSize = 2;
        transformation.data[1][2] = 1;
        transformation.data[2][1] = 1;
        transformation.data[2][2] = 1;
        matrix identity;
        identity.rowSize = 2;
        identity.columnSize = 1;
        identity.data[2][1] = 1;
        MODULO --;
        matrix result = transformation.power(N) * identity;
        int f = result.data[1][1];
        MODULO ++;
        cout << power(2, f, MODULO) << endl;
    }
    
    return 0;
}
