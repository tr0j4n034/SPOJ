//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/17/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Problem can also be solved by using dfs.
 Here just approach the order of nodes as opening/closing brackets.
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

const int S = 1 << 10;

int T, N;
int order[S];
int was[S], children[S];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> N;
        for (int i = 1; i <= N + N; i ++) {
            cin >> order[i];
        }
        for (int i = 1; i <= N; i ++) {
            children[i] = 0;
            was[i] = 0;
        }
        stack<int> open;
        for (int i = 1; i <= N + N; i ++) {
            if (!was[order[i]]) {
                if (!open.empty()) {
                    children[open.top()] ++;
                }
                was[order[i]] = 1;
                open.push(order[i]);
            } else {
                open.pop();
            }
        }
        cout << "Case " << c + 1 << ":" << endl;
        for (int i = 1; i <= N; i ++) {
            cout << i << " -> " << children[i] << endl;
        }
        if (c < T - 1) {
            cout << endl;
        }
    }
    
    return 0;
}

