//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/20/19.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(T * M * log(N)) solution using Dijkstra's algorithm
 Suppose that one of the given K edges, (u, v, l) is the best edge to add to the graph.
 Then, our shortest path from source to destination looks like
    d(source, destination) = d(source, u) + l + d(destination, v)
 This suffices calculation of distances from both source and destination to all other nodes.
 It can be done via 2 Dijkstra passes. 
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct edge{
    int from;
    int to;
    int weight;
    edge() {}
    edge(int __from, int __to, int __weight) {
        from = __from;
        to = __to;
        weight = __weight;
    }
};

typedef vector<vector<edge>> graph;

int T, N, M, K;
int source, destination;

int main(int argc, const char * argv[]) {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%d%d%d", &N, &M, &K, &source, &destination);
        graph G(N + 1), GRev(N + 1);
        for (int i = 0; i < M; i ++) {
            int from, to, weight;
            scanf("%d%d%d", &from, &to, &weight);
            G[from].push_back(edge(from, to, weight));
            GRev[to].push_back(edge(to, from, weight));
        }
        vector<edge> proposedEdges(K);
        for (auto &edge: proposedEdges) {
            scanf("%d%d%d", &edge.from, &edge.to, &edge.weight);
        }
        auto dijkstra = [&](int source, graph G) {
            vector<int> distances(N + 1, 1 << 29);
            distances[source] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
            Q.push(make_pair(0, source));
            while (!Q.empty()) {
                auto data = Q.top();
                Q.pop();
                int nodeDistance = data.first;
                int nodeId = data.second;
                for (auto edge: G[nodeId]) {
                    if (distances[edge.to] > nodeDistance + edge.weight) {
                        distances[edge.to] = nodeDistance + edge.weight;
                        Q.push(make_pair(distances[edge.to], edge.to));
                    }
                }
            }
            return distances;
        };
        auto forward = dijkstra(source, G);
        auto backward = dijkstra(destination, GRev);
        int result = forward[destination];
        for (auto edge: proposedEdges) {
            result = min(result, forward[edge.from] + edge.weight + backward[edge.to]);
            result = min(result, forward[edge.to] + edge.weight + backward[edge.from]);
        }
        printf("%d\n", (result < (1 << 29)) ? result : -1);
    }
    
    return 0;
}
