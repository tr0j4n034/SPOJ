//
//  main.cpp
//  practice
//
//  Created by Mahmud on 11/04/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10000001;

int counter;
int composite[MAX];

int main() {
    composite[1] = 1;
    for (int i = 2; i * i < MAX; i ++) {
        if (!composite[i]) {
            for (int j = i * i; j < MAX; j += i) {
                composite[j] = 1;
            }
        }
    }
    for (int i = 2; i < MAX; i ++) {
        if (!composite[i]) {
            counter ++;
            if (!composite[counter]) {
                printf("%d\n", i);
            }
        }
    }
    
    return 0;
}
