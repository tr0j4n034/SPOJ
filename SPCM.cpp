//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/25/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

template <class T>
vector<pair<T, int>> factorize(T N) {
    vector<pair<T, int>> v;
    for (int i = 2; 1LL * i * i <= N; i ++) {
        if (N % i == 0) {
            int cnt = 0;
            while (N % i == 0) {
                cnt ++;
                N /= i;
            }
            v.emplace_back(i, cnt);
        }
    }
    if (N > 1) v.emplace_back(N, 1);
    return v;
}
template <class T>
int f(T N) {
    auto r = factorize(N);
    if ((int)r.size() == 1 && r[0].second == 1) {
        return 1;
    } else {
        long long sum = 0;
        for (auto i : r) sum += i.first;
        return f(sum) + (int)r.size();
    }
}
int main() {
    int T;
    long long N;
    
    cin >> T;
    while (T --) {
        cin >> N;
        cout << f(N) << endl;
    }
    
    return 0;
}
