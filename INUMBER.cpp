//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/02/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 1005;

string bfs(int N) {
    if (N < 10) return to_string(N);
    int was[MAX][MAX] = {0};
    for (int i = 0; i <= N; i ++) {
        for (int j = 0; j <= N; j ++) was[i][j] = 0;
    }
    queue<pair<string, pair<int, int>>> Q;
    for (int i = 1; i < 10; i ++) {
        Q.push(make_pair(to_string(i), make_pair(i, i)));
        was[i][i] = 1;
    }
    while (!Q.empty()) {
        pair<string, pair<int, int>> current = Q.front();
        Q.pop();
        int remainder = current.second.first;
        int sum = current.second.second;
        string s = current.first;
        if (remainder == 0 && sum == N) return current.first;
        if (sum > N) continue;
        for (int i = 0; i < 10; i ++) {
            if (!was[(remainder * 10 + i) % N][sum + i]) {
                was[(remainder * 10 + i) % N][sum + i] = 1;
                Q.push(make_pair(s + (char)(i + '0'), make_pair((remainder * 10 + i) % N, sum + i)));
            }
        }
    }
    return "-1";
}

int main() {
    int T, N;
    
    cin >> T;
    while (T --) {
        cin >> N;
        cout << bfs(N) << endl;
    }
    
    return 0;
}
