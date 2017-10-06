//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/6/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 An O(N * log(N)) solution
 It seems for this problem priority queue is a bit faster, because
 the same solution with multisets gets time limit exceeded verdict.
 Basically we keep two sorted sequence all the time: lower half and upper half
 When adding a new element, we need to track only their extreme elements.
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int modulo = 1000000007;

int T, N, A, B, C;

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%d%d", &A, &B, &C, &N);
        priority_queue<int, vector<int>, less<int>> bottomHalf;
        priority_queue<int, vector<int>, greater<int>> topHalf;
        bottomHalf.push(1);
        
        int bottomSize = 1, topSize = 0;
        long long result = 1;
        for (int i = 2; i <= N; i ++) {
            int median = bottomHalf.top();
            int current = (1LL * A * median + 1LL * B * i + C) % modulo;
            bottomHalf.push(current);
            bottomSize ++;
            while (bottomSize > topSize) {
                int value = bottomHalf.top();
                bottomHalf.pop();
                topHalf.push(value);
                bottomSize --;
                topSize ++;
            }
            while (bottomSize < topSize) {
                int value = topHalf.top();
                topHalf.pop();
                bottomHalf.push(value);
                bottomSize ++;
                topSize --;
            }
            while ((!bottomHalf.empty()) && (!topHalf.empty()) && bottomHalf.top() > topHalf.top()) {
                int value1 = bottomHalf.top();
                int value2 = topHalf.top();
                bottomHalf.pop();
                topHalf.pop();
                bottomHalf.push(value2);
                topHalf.push(value1);
            }
            result += current;
        }
        cout << result << endl;
    }
    
    return 0;
}


