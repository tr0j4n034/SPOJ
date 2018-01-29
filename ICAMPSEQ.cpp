//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/29/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 An O(N) solution with proper fast input techniques
 To solve the problem, we only need to check the distances
  from each point to
   only 2 * 2^4 = 32 extremum points.
 The extremum points are the ones with +- minimum and maximum sum values with the whole data.
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAX = 100005;

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
template <class T>
void fastInputReal(T &N) {
    char ch;
    int sign = 1;
    N = 0.;
    while ((ch = getchar_unlocked()) && ch == ' ') {};
    if (ch == '-') sign = -1;
    else if (isdigit(ch)) N = ch - '0';
    while ((ch = getchar_unlocked()) && isdigit(ch)) {
        N = 10 * N + ch - '0';
    }
    if (ch == '.') { // read fractional part
        double r = 0.;
        while ((ch = getchar_unlocked()) && isdigit(ch)) {
            r = 10 * r + ch - '0';
        }
        while (r > 1) r /= 10.;
        N += r;
    }
    if (sign == -1) N = 1. * N;
}

int N;
double data[MAX][4];
int extremum[2][16];

int main() {
    //fastInput(N);
    scanf("%d", &N);
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < 4; j ++) {
            scanf("%lf", &data[i][j]);
            //fastInputReal(data[i][j]);
        }
    }
    for (int i = 0; i < 16; i ++) {
        extremum[0][i] = -1;
        extremum[1][i] = -1;
        double minimum = 1.e20;
        double maximum = -1.e20;
        for (int j = 0; j < N; j ++) {
            double current = 0.;
            for (int k = 0; k < 4; k ++) {
                if (i & (1 << k)) current += data[j][k];
                else current -= data[j][k];
            }
            if (current < minimum) {
                minimum = current;
                extremum[0][i] = j;
            }
            if (current > maximum) {
                maximum = current;
                extremum[1][i] = j;
            }
        }
    }
    double result = 0.;
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 16; j ++) {
            for (int k = 0; k < N; k ++) {
                double current = 0.;
                for (int q = 0; q < 4; q ++) {
                    current += fabs(data[extremum[i][j]][q] - data[k][q]);
                }
                if (current > result) result = current;
            }
        }
    }
    cout.precision(3);
    cout << fixed << result << endl;
    
    return 0;
}
