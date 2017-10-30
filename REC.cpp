//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/30/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(T * log(N)) solution using matrix exponentation.
 Transformation matrix will be a simple 2x2 matrix.
 
 | a 1 | * | F(n - 1) | = | F(n) |
 | 0 1 |   |    b     | = |  b   |
 
 
 We can get rid of big values of "a" and "b" by calculating their modulos to "M".
 It's better to write your own division and modulo operators...
 */

#include <iostream>
#include <cassert>

using namespace std;

const int SIZE = 4;
//const int MODULO = 1000000007;
int MODULO;

struct Number{ // positive
    string digits;
    
    Number() {
        digits = "";
    }
    Number(string _digits):
    digits(_digits) {
        
    }
    void read() {
        cin >> digits;
        return;
        char ch;
        digits = "";
        while ((ch = getchar()) && !isdigit(ch)) {
            
        }
        digits += ch;
        while ((ch = getchar()) && isdigit(ch)) {
            digits += ch;
        }
    }
    Number operator / (int d) {
        string result = "";
        int now = 0;
        for (int i = 0; i < (int)digits.size(); i ++) {
            now = now * 10 + digits[i] - '0';
            if (!result.empty() || now / d > 0) {
                result += ((char)(now / d) + '0');
            }
            now %= d;
        }
        if (result.empty()) {
            result = "0";
        }
        return (Number)(result);
    }
    int operator % (int d) {
        int now = 0;
        for (int i = 0; i < (int)digits.size(); i ++) {
            now = now * 10 + digits[i] - '0';
            now %= d;
        }
        return now;
    }
};

struct matrix{
    int rowSize = SIZE - 1;
    int columnSize = SIZE - 1;
    int data[SIZE][SIZE];
    matrix() {
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
        result.columnSize = columnSize;
        return result;
    }
    matrix power(Number e) {
        if (e.digits == "1") {
            return *this;
        }
        matrix half = power(e / 2);
        half = half * half;
        if ((int)(e.digits.back()) % 2) {
            half = half * (*this);
        }
        return half;
    }
};

int T;

int main() {
    scanf("%d", &T);
    while (T --) {
        Number a, b, n;
        a.read();
        b.read();
        n.read();
        scanf("%d", &MODULO);
        if (n.digits == "0") {
            printf("%d\n", 1 % MODULO);
            continue;
        }
        matrix transformation, identity;
        transformation.rowSize = 2;
        transformation.columnSize = 2;
        transformation.data[1][1] = a % MODULO;
        transformation.data[1][2] = 1;
        transformation.data[2][2] = 1;
        
        identity.rowSize = 2;
        identity.columnSize = 1;
        identity.data[1][1] = 1;
        identity.data[2][1] = b % MODULO;
        
        matrix result = transformation.power(n) * identity;
        printf("%d\n", result.data[1][1]);
    }
    
    return 0;
}
