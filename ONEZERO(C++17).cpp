//
//  main.cpp
//  practice
//
//  Created by Mahmud on 01/17/19.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int T, N;
vector<int> queries;

int main(int argc, const char * argv[]) {
    cin >> T;
    for (int i = 0; i < T; i ++) {
        cin >> N;
        queries.push_back(N);
    }
    auto solver = [](int N) -> string {
        if (N == 1) return "1";
        queue<int> Q;
        vector<string> multiples(N, "");
        Q.push(1);
        multiples[1] = "1";
        while (!Q.empty()) {
            int current = Q.front();
            Q.pop();
            for (int addend: {0, 1}) {
                int to = (current * 10 + addend) % N;
                if (multiples[to].empty()) {
                    Q.push(to);
                    multiples[to] = multiples[current] + (char)(addend + '0');
                }
            }
        }
        return multiples[0];
    };
    for_each(queries.begin(), queries.end(), [&](int N) {
        cout << solver(N) << endl;
    });
    
    return 0;
}

