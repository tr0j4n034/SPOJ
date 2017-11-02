//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/02/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(Q * MAX(N) / 32) solution using bitsets
 MAX(N) defines maximum of input numbers which can be up to 20000.
 32 factor comes from bitsets (basically, it is 32 times faster than normal boolean array).
 For more precise definition of bitsets, please google it.
 Every query is just playing with bitsets :).
 Note: The solution can be boosted at least 2 times with implementing your 64-bit bitset technique.
 And if you need more interesting problem related to bitsets, you can try the following one:
 http://www.spoj.com/problems/ADATOMEL/
 */

#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

const int MAX = 20005;

int N, Q;
bitset<MAX> bs[MAX];

int main() {
    scanf("%d", &Q);
    while (Q --) {
        char ch;
        int x, y;
        scanf(" %c%d%d", &ch, &x, &y);
        if (ch == '+') {
            bs[x][y] = 1;
        }
        else if(ch == '-') {
            bs[x][y] = 0;
        }
        else if (ch == 'v') {
            printf("%d\n", int((bs[x] | bs[y]).count()));
        }
        else if(ch == '^') {
            printf("%d\n", int((bs[x] & bs[y]).count()));
        }
        else if(ch == '!') {
            printf("%d\n", int((bs[x] | bs[y]).count()) - int((bs[x] & bs[y]).count()));
        }
        else {
            printf("%d\n", int((bs[x] ^ (bs[x] & bs[y])).count()));
        }
    }
    
    return 0;
}
