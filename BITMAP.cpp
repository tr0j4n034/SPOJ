//
// main.cpp
// practice
//
// Created by Mahmud 8/21/2017.
// Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 205;

int T, N, M;
char ch;
int distances[MAX][MAX];
char input[MAX][MAX];

int main (int argc, const char * argv[]) {
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		getchar_unlocked();
		for (int i = 1; i <= N; i ++) {
			for (int j = 1; (ch = getchar_unlocked()) != '\n'; j ++) {
				input[i][j] = ch;
				distances[i][j] = 123456;
			}
		}
		queue<pair<int, int> > Q;
		for (int i = 1; i <= N; i ++) {
			for (int j = 1; j <= M; j ++) {
				if (input[i][j] == '1') {
					distances[i][j] = 0;
					Q.push(make_pair(i, j));
				}
			}
		}
		while (!Q.empty()) {
			pair<int, int> current = Q.front();
			Q.pop();
			int x = current.first;
			int y = current.second;
			for (int i = -1; i < 2; i ++) {
				for (int j = -1; j < 2; j ++) {
					if (i * i + j * j == 1) {
						int tox = x + i;
						int toy = y + j;
						if (tox > 0 && tox <= N && toy > 0 && toy <= M) {
							if (distances[tox][toy] == 123456) {
								Q.push(make_pair(tox, toy));
								distances[tox][toy] = distances[x][y] + 1;
							}
						}
					}
				}
			}
		}
		for (int i = 1; i <= N; i ++) {
			for (int j = 1; j <= M; j ++) {
				printf("%d", distances[i][j]);
				if (j < M) {
					putchar_unlocked(' ');
				}
			}
			putchar_unlocked('\n');
		}
	}

	return 0;
}

