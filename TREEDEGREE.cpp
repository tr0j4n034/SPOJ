//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/13/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 A simple O(T * N) solution
 Problem can be solved using dfs or some other techniques as well.
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

const int S = 1 << 18;

int T, N;
int order[S];
int was[S], neighbors[S];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T --) {
        cin >> N;
        for (int i = 1; i <= N + N; i ++) {
            cin >> order[i];
        }
        for (int i = 1; i <= N; i ++) {
            neighbors[i] = 0;
            was[i] = 0;
        }
        stack<int> open;
        for (int i = 1; i <= N + N; i ++) {
            if (!was[order[i]]) {
                if (!open.empty()) {
                    neighbors[open.top()] ++;
                    neighbors[order[i]] ++;
                }
                was[order[i]] = 1;
                open.push(order[i]);
            } else {
                open.pop();
            }
        }
        cout << *max_element(neighbors, neighbors + N + 1) << endl;
    }
    
    return 0;
}

