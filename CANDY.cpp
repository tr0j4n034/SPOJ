//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/20/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10005;

int N;
int data[MAX];

int main() {
    while(scanf("%d", &N) != EOF) {
        if (N == -1) {
            break;
        }
        int sum = 0;
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &data[i]);
            sum += data[i];
        }
        if (sum % N) {
            puts("-1");
        }
        else {
            int moves = 0;
            for (int i = 1; i <= N; i ++) {
                if (data[i] < sum / N) {
                    moves += sum / N - data[i];
                }
            }
            printf("%d\n", moves);
        }
    }
    
    return 0;
}
