//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/09/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Since the graph is randomly generated, the following solution
    with bitsets work fast.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

const int GRAPH_SIZE = 900;

int N;
vector<int> graph[GRAPH_SIZE];
bitset<GRAPH_SIZE> bs[GRAPH_SIZE];

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = -1; i < N; i ++) {
        string line;
        getline(cin, line);
        line += " ";
        if (i == -1) {
            continue;
        }
        int value = 0;
        for (char ch: line) {
            if (ch == ' ') {
                graph[i].push_back(value);
                bs[i][value] = 1;
                value = 0;
            } else {
                value = 10 * value + ch - '0';
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i ++) {
        for (int j: graph[i]) {
            if (j < i) {
                continue;
            }
            bitset<GRAPH_SIZE> current = bs[i] & bs[j];
            for (int k: graph[j]) {
                if (k < j) {
                    continue;
                }
                if (bs[i][k]) {
                    result += (current & bs[k]).count();
                }
            }
        }
    }
    cout << result / 4 << endl;
    
    //cout << "clock = " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

