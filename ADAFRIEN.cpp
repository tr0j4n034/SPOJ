//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/12/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <utility>

using namespace std;

const int MAX = 100005;

int N, K;
long long result = 0;
map<string, long long> m;
vector<long long> costs;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> N >> K) {
        if (cin.eof()) {
            break;
        }
        result = 0;
        m.clear();
        costs.clear();
        for (int i = 0; i < N; i ++) {
            string word;
            int value;
            cin >> word >> value;
            m[word] += value;
        }
        for (auto i : m) {
            costs.push_back(i.second);
        }
        sort(costs.begin(), costs.end(), greater<long long>());
        for (auto i : costs) {
            if (K > 0) {
                result += i;
                K --;
            }
        }
        cout << result << endl;
    }
    
    return 0;
}
