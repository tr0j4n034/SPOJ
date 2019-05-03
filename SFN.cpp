//
//  main.cpp
//  practice
//
//  Created by Mahmud on 05/03/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

/*
 O(T * log(N) [* 10^3]) solution via matrix exponentiation.
 Suppose that you already know the number of possible combinations
  of length l starting with digit i and ending with digit.
  Then you can build combinations for length 2 * l or l + 1.
  This part can be done using a merge routine similar to the one below.
 */

#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > combination;

const int MODULO = 1000000007;

void add(int &a, int b) {
    a += b;
    if (a >= MODULO) a -= MODULO;
}
int isSquare(int x) {
    return x == 1 || x == 4 || x == 9 || x == 16;
}

combination merge(combination lhs, combination rhs) {
    combination result;
    
    result.resize(10);
    for (auto& row: result) row.resize(10);
    for (int i = 1; i < 10; i ++) {
        for (int j = 1; j < 10; j ++) {
            if (!lhs[i][j]) continue;
            for (int k = 1; k < 10; k ++) {
                if (isSquare(j + k)) continue;
                for (int q = 1; q < 10; q ++) {
                    add(result[i][q], 1LL * lhs[i][j] * 1LL * rhs[k][q] % MODULO);
                }
            }
        }
    }
    return result;
}
combination solve(long long length) {
    if (length == 1) {
        combination unit;
        
        unit.resize(10);
        for (auto& row: unit) row.resize(10);
        for (int i = 1; i < 10; i ++) {
            unit[i][i] = 1;
        }
        return unit;
    }
    if (length & 1) {
        combination unit = solve(1);
        combination rhs = solve(length - 1);
        return merge(unit, rhs);
    } else {
        combination half = solve(length >> 1);
        return merge(half, half);
    }
}

int main(int argc, const char* argv[]) {
    int T;
    long long N;
    
    cin >> T;
    while (T --) {
        cin >> N;
        if (N == 1) {
            cout << 6 << endl;
            continue;
        }
        combination result = solve(N);
        int sum = 0;
        for (int i = 1; i < 10; i ++) {
            for (int j = 1; j < 10; j ++) {
                add(sum, result[i][j]);
            }
        }
        cout << sum << endl;
    }
    
    return 0;
}

