
// main.cpp
// practice
//
// Created by Mahmud 8/29/2017.
// Copyright © 2017 Mahmud. All rights reserved.
//

/*
    Make BFS from both starting points and
    compare distances
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 1005;

int T, N;
int x[2], y[2];
int distances[2][MAX][MAX];
char grid[MAX][MAX];

int main (int argc, const char * argv[]) {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        getchar_unlocked();
        for (int i = 1; i <= N; i ++) {
            char ch;
            for (int j = 1; (ch = getchar_unlocked()) != '\n'; j ++) {
                grid[i][j] = ch;
                if (grid[i][j] == 'X') {
                    x[0] = i, y[0] = j;
                }
                else if(grid[i][j] == 'Y') {
                    x[1] = i, y[1] = j;
                }
            }
        }
        for (int _ = 0; _ < 2; _ ++) {
            for (int i = 1; i <= N; i ++) {
                for (int j = 1; j <= N; j ++) {
                    distances[_][i][j] = 123456;
                }
            }
            distances[_][x[_]][y[_]] = 0;
            queue<pair<int, int> > Q;
            Q.push(make_pair(x[_], y[_]));
            while (!Q.empty()) {
                pair<int, int> current = Q.front();
                int cx = current.first;
                int cy = current.second;
                Q.pop();
                for (int i = -1; i < 2; i ++) {
                    for (int j = -1; j < 2; j ++) {
                        if (i * i + j * j == 1) {
                            if (cx + i > 0 && cx + i <= N && cy + j > 0 && cy + j <= N) {
                                if (grid[cx + i][cy + j] != 'B' && distances[_][cx + i][cy + j] == 123456) {
                                    distances[_][cx + i][cy + j] = distances[_][cx][cy] + 1;
                                    Q.push(make_pair(cx + i, cy + j));
                                }
                            }
                        }
                    }
                }
            }
        }
        int delta = 0;
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= N; j ++) {
                if (grid[i][j] == 'b') {
                    if (distances[0][i][j] < distances[1][i][j]) {
                        delta ++;
                    }
                    else if(distances[0][i][j] > distances[1][i][j]) {
                        delta --;
                    }
                }
            }
        }
        if (delta > 0) {
            puts("Pack 1");
        }
        else if(delta < 0) {
            puts("Pack 2");
        }
        else {
            puts("Gru gets to keep all bananas!");
        }
    }	
    
    return 0;
}
