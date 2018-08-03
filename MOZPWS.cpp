//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <climits>

using namespace std;

const int S = 100005;
const int LOG = 18;

int T, N, K, Q;
long long data[S];
long long f[S], rmqtable[LOG][S];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> N >> K;
        for (int i = 1; i <= N; i ++) {
            cin >> data[i];
        }
        // this part can also be done with stacks in linear time
        multiset<long long> s;
        for (int i = 1; i <= N; i ++) {
            if (i > K) {
                s.erase(s.find(data[i - K]));
            }
            s.insert(data[i]);
            if (i >= K) {
                f[i - K + 1] = *s.begin();
            }
        }
        int M = N - K + 1;
        for (int i = 1; i <= M; i ++) {
            rmqtable[0][i] = f[i];
        }
        for (int i = 1; i < LOG; i ++) {
            for (int j = 1; j + (1 << i) - 1 <= M; j ++) {
                rmqtable[i][j] = max(rmqtable[i - 1][j], rmqtable[i - 1][j + (1 << (i - 1))]);
            }
        }
        auto calculateMin = [](int l, int r) {
            r -= K - 1;
            int d = 31 - __builtin_clz(r - l + 1);
            return max(rmqtable[d][l], rmqtable[d][r - (1 << d) + 1]);
        };
        cin >> Q;
        cout << "Case " << c + 1 << ":" << endl;
        while (Q --) {
            int l, r;
            cin >> l >> r;
            if (r - l + 1 < K) {
                cout << "Impossible" << endl;
            } else {
                cout << calculateMin(l, r) << endl;
            }
        }
    }
    
    return 0;
}
