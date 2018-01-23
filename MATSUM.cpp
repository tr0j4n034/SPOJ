//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/23/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 A solution based on Fenwick trees.
 Each query can be answered in O(log^2(N)).
 Learning methods in 'functional' library))
 */

#include <iostream>
#include <functional>

using namespace std;

int tests;
int N;
char type[3];

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

int main() {
    function<void(int **, int, int, int)> update = [](int **ftree, int x, int y, int value){
        for (int i = x; i <= N; i += (i & -i)) {
            for (int j = y; j <= N; j += (j & -j)) {
                ftree[i][j] += value;
            }
        }
    };
    function<int(int **, int, int)> getSum = [](int ** ftree, int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= (i & -i)) {
            for (int j = y; j > 0; j -= (j & -j)) {
                sum += ftree[i][j];
            }
        }
        return sum;
    };
    
    function<void(ostream&, int)> print = [](ostream &os, int N) {
        os << N;
        os << '\n';
    };
    
    fastInput(tests);
    while (tests --) {
        fastInput(N);
        ostream out(nullptr);
        int **ftree = (int**)calloc(N + 1, sizeof(int));
        for (int i = 0; i <= N; i ++) ftree[i] = (int*)calloc(N + 1, sizeof(int));
        
        while (scanf("%s", type)) {
            if (type[0] == 'E') break; // end
            if (type[1] == 'E') { // set
                int x, y, value;
                fastInput(x); ++x;
                fastInput(y); ++y;
                fastInput(value);
                int oldValue = getSum(ftree, x, y) - getSum(ftree, x - 1, y)
                - getSum(ftree, x, y - 1) + getSum(ftree, x - 1, y - 1);
                update(ftree, x, y, -oldValue);
                update(ftree, x, y, value);
            } else { // query
                int x1, y1, x2, y2;
                fastInput(x1); ++x1;
                fastInput(y1); ++y1;
                fastInput(x2); ++x2;
                fastInput(y2); ++y2;
                print(std::cout, getSum(ftree,x2, y2) - getSum(ftree, x1 - 1, y2)
                      - getSum(ftree, x2, y1 - 1) + getSum(ftree, x1 - 1, y1 - 1));
            }
        }
        putchar_unlocked('\n');
    }
    
    return 0;
}
