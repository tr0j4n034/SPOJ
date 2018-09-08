//
//  main.cpp
//  practice
//
//  Created by Mahmud on 9/8/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 A well-known problem which is (usually) solved by using stacks
 Consider that the optimal solution contains i-th block. Then surely,
    there must be a consecutive segment of blocks on the left and right side
    of i-th block all having heigt greater or equal high to i-th one.
 This part is handled using 'monotone' stacks technique.
 */

#include <iostream>
#include <cstdio>
#include <stack>
#include <utility>

using namespace std;

const int S = 1 << 18;

int N;
int data[S];
int leftBorders[S], rightBorders[S];

int main() {
    while (scanf("%d", &N)) {
        if (N == 0) {
            break;
        } for (int i = 1; i <= N; i ++) {
            scanf("%d", &data[i]);
        }
        stack<pair<int, int>> s;
        for (int i = 1; i <= N; i ++) { // getting left borders
            while (!s.empty() && s.top().first >= data[i]) {
                s.pop();
            } leftBorders[i] = (s.empty() ? 1 : s.top().second + 1);
            s.push(make_pair(data[i], i));
        } while (!s.empty()) {
            s.pop();
        } for (int i = N; i > 0; i --) { // getting right borders
            while (!s.empty() && s.top().first >= data[i]) {
                s.pop();
            } rightBorders[i] = (s.empty() ? N : s.top().second - 1);
            s.push(make_pair(data[i], i));
        }
        long long result = 0;
        for (int i = 1; i <= N; i ++) {
            long long area = 1LL * data[i] * (rightBorders[i] - leftBorders[i] + 1);
            if (area > result) {
                result = area;
            }
        }
        cout << result << endl;
    }
    
    return 0;
}

