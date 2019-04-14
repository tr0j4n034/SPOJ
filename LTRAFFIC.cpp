//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/14/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

/*
 We can do one BFS from the starting position and calculate
  the distances to all the grid points in O(N * M) time.
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

int N, M, Q;
int x, y;
vector<vector<int>> grid;
vector<pair<int, int>> importantPoints;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> Q;
    grid.resize(N);
    for (int i = 0; i < N; i ++) {
        string line;
        cin >> line;
        grid[i].resize(M);
        transform(line.begin(), line.end(), grid[i].begin(), [&](char ch) {
            return ch == '1';
        });
    }
    vector<vector<int>> distances(N);
    for (int i = 0; i < N; i ++) {
        distances[i].assign(M, INT_MAX);
    }
    cin >> x >> y; --x; --y;
    distances[x][y] = 0;
    for (int i = 0; i < Q; i ++) {
        int vx, vy;
        cin >> vx >> vy;
        importantPoints.emplace_back(vx - 1, vy - 1);
    }
    queue<pair<int, int>> Q;
    Q.emplace(x, y);
    while (!Q.empty()) {
        pair<int, int> current = Q.front();
        Q.pop();
        for (int i = -1; i < 2; i ++) {
            for (int j = -1; j < 2; j ++) {
                if (i * i + j * j != 1) continue;
                int tox = current.first + i;
                int toy = current.second + j;
                if (tox < 0 || tox >= N | toy < 0 || toy >= M) continue;
                if (!grid[tox][toy]) continue;
                if (distances[tox][toy] == INT_MAX) {
                    distances[tox][toy] = distances[current.first][current.second] + 1;
                    Q.emplace(tox, toy);
                }
            }
        }
    }
    int nearest = INT_MAX;
    for_each(importantPoints.begin(), importantPoints.end(), [&](auto point) {
        nearest = min(nearest, distances[point.first][point.second]);
    });
    
    cout << (nearest == INT_MAX ? -1 : nearest) << endl;
    
    return 0;
}

