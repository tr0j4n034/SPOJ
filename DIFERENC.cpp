//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/8/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <stack>
#include <utility>

using namespace std;

const int S = 300005;

int N;
int a[S], l[2][S], r[2][S];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i ++) cin >> a[i];
    
    stack<pair<int, int>> s;
    for (int i = 1; i <= N; i ++) { // left bigger
        while (!s.empty() && s.top().first <= a[i]) {
            s.pop();
        }
        l[0][i] = s.empty() ? 1 : s.top().second + 1;
        s.push(make_pair(a[i], i));
    }
    while (!s.empty()) s.pop();
    for (int i = N; i > 0; i --) { // right bigger
        while (!s.empty() && s.top().first < a[i]) {
            s.pop();
        }
        r[0][i] = s.empty() ? N : s.top().second - 1;
        s.push(make_pair(a[i], i));
    }
    while (!s.empty()) s.pop();
    for (int i = 1; i <= N; i ++) { // left smaller
        while (!s.empty() && s.top().first >= a[i]) {
            s.pop();
        }
        l[1][i] = s.empty() ? 1 : s.top().second + 1;
        s.push(make_pair(a[i], i));
    }
    while (!s.empty()) s.pop();
    for (int i = N; i > 0; i --) { // right smaller
        while (!s.empty() && s.top().first > a[i]) {
            s.pop();
        }
        r[1][i] = s.empty() ? N : s.top().second - 1;
        s.push(make_pair(a[i], i));
    }
    long long result = 0;
    for (int i = 1; i <= N; i ++) {
        long long adds = 1LL * (r[0][i] - i + 1) * (i - l[0][i] + 1);
        long long subtracts = 1LL * (r[1][i] - i + 1) * (i - l[1][i] + 1);
        result += 1LL * (adds - subtracts) * a[i];
    }
    cout << result << endl;
    
    return 0;
}
