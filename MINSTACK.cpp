//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/28/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Enhancing stack to support
    retrieval of minimum element in current stack in O(1).
 The idea is to keep the data value as a pair in stack,
    where the pair consists of the value of the element itself and
        the minimum value seen so far.
 */

#include <iostream>
#include <cstdio>
#include <stack>
#include <utility>

using namespace std;

int Q;
int value;
char type[10];
stack<pair<int, int>> minStack;

int main(int argc, const char * argv[]) {
    scanf("%d", &Q); getchar();
    while (Q --) {
        scanf("%s", type);
        if (type[1] == 'U') { // PUSH
            scanf("%d", &value);
            minStack.push(make_pair(value, minStack.empty() ? value: min(minStack.top().second, value)));
        } else if (type[1] == 'O') { // POP
            if (minStack.empty()) {
                puts("EMPTY");
            } else {
                minStack.pop();
            }
        }
        else { // MIN
            if (minStack.empty()) {
                puts("EMPTY");
            } else {
                printf("%d\n", minStack.top().second);
            }
        }
    }
    
    return 0;
}
