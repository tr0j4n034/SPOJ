//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/27/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n, m, a, b;
    while(scanf("%d%d%d%d", &n, &m, &a, &b) != EOF) {
        if(n + m + a + b == 0) {
            break;
        }
        vector<int> citiesA, citiesB;
        vector<int> distances(n + 1, 1 << 30);
        vector<vector<pair<int, int>>> edges(n + 1);
        for(int i = 0; i < a; i ++) {
            int id;
            scanf("%d", &id);
            citiesA.push_back(id);
            edges[0].push_back(make_pair(id, 0));
            edges[id].push_back(make_pair(0, 0));
        }
        for(int i = 0; i < b; i ++) {
            int id;
            scanf("%d", &id);
            citiesB.push_back(id);
            edges[n].push_back(make_pair(id, 0));
            edges[id].push_back(make_pair(n, 0));
        }
        for(int i = 0; i < m; i ++) {
            int from, to, length;
            scanf("%d%d%d", &from, &to, &length);
            edges[from].push_back(make_pair(to, length));
            edges[to].push_back(make_pair(from, length));
        }
        // Dijkstra
        priority_queue<pair<int, int>> Q;
        Q.push(make_pair(0, 0));
        while(!Q.empty()) {
            pair<int, int> current = Q.top();
            Q.pop();
            int id = current.second;
            int d = current.first;
            if(d > distances[id]) {
                continue;
            }
            for(auto i : edges[id]) {
                if(distances[i.first] > d + i.second) {
                    distances[i.first] = d + i.second;
                    Q.push(make_pair(distances[i.first], i.first));
                }
            }
        }
        printf("%d\n", distances[n]);
    }
    
    return 0;
}
