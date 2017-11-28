//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/28/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N^3*log(N)) solution using Kadane's algorithm.
 We need to fix lower and upper row for submatrices,
  then number of submatrices for specific ranges can be calculated using Fenwick trees and prefix sums.
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cassert>

using namespace std;

const int MAX = 255;
const int FTREE_MAX = MAX * 3;

int N, M;
int A, B;
int data[MAX][MAX], columnSum[MAX][MAX];
int ftree[MAX];

void add(int position, int value) {
    for ( ; position < FTREE_MAX; position += (position & -position)) {
        ftree[position] += value;
    }
}
int get(int position) {
    int sum = 0;
    for ( ; position > 0; position -= (position & -position)) {
        sum += ftree[position];
    }
    return sum;
}
int get(int l, int r) {
    return get(r) - get(l - 1);
}

int main() {
    srand(unsigned(time(NULL)));
    
    scanf("%d%d", &N, &M);
    //N = rand() % 100 + 1;
    //M = rand() % 100 + 1;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            scanf("%d", &data[i][j]);
            //data[i][j] = (rand() % 3 > 0 ? 1 : -1) * (rand() % 1000);
            columnSum[i][j] = columnSum[i - 1][j] + data[i][j];
        }
    }
    scanf("%d%d", &A, &B);
    //A = rand() % 5005;
    //B = rand() % 5005;
    if (A > B) {
        swap(A, B);
    }
    //cout << "matrix now: " << endl;
    //cout << N << " " << M << endl;
    //for (int i = 1; i <= N; i ++) {
    //    for (int j = 1; j <= M; j ++) {
    //        cout << data[i][j] << ", ";
    //    }
    //    cout << endl;
    //}
    //cout << A << " " << B << endl;
    //cout << endl;
    
    
    long long result = 0, bruteResult = 0;
    for (int i = 1; i <= N; i ++) {
        for (int j = i; j <= N; j ++) {
            vector<int> values(M * 3 + 1);
            int current = 0;
            for (int k = 1; k <= M; k ++) {
                current += columnSum[j][k] - columnSum[i - 1][k];
                values[(k - 1) * 3] = current;
                values[(k - 1) * 3 + 1] = current - A;
                values[(k - 1) * 3 + 2] = current - B;
            }
            values[3 * M] = 0;
            sort(values.begin(), values.end());
            values.erase(unique(values.begin(), values.end()), values.end());
            fill(ftree, ftree + FTREE_MAX, 0);
            
            current = 0;
            int zeroPosition = (int)(lower_bound(values.begin(), values.end(), 0) - values.begin()) + 1;
            add(zeroPosition, 1);
            
            for (int k = 1; k <= M; k ++) {
                current += columnSum[j][k] - columnSum[i - 1][k];
                int low = (int)(lower_bound(values.begin(), values.end(), current - B) - values.begin()) + 1;
                int high = (int)(lower_bound(values.begin(), values.end(), current - A) - values.begin()) + 1;
                int currentPosition = (int)(lower_bound(values.begin(), values.end(), current) - values.begin()) + 1;
                result += get(low, high);
                add(currentPosition, 1);
            }
            //for (int k = 1; k <= M; k ++) {
            //    int bruteSum = 0;
            //    for (int q = k; q <= M; q ++) {
            //        bruteSum += columnSum[j][q] - columnSum[i - 1][q];
            //        if (bruteSum >= A && bruteSum <= B) {
            //            bruteResult ++;
            //        }
            //    }
            //}
            //assert(result == bruteResult);
        }
    }
    //cout << bruteResult << endl;
    cout << result << endl;
    
    return 0;
}
