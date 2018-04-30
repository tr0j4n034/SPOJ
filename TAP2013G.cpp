//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int MAX = 100005;

int N;
multiset<int> a, b;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i ++) {
        int x;
        scanf("%d", &x);
        a.insert(x);
    }
    for (int i = 0; i < N; i ++) {
        int x;
        scanf("%d", &x);
        b.insert(x);
    }
    int result = 0;
    while (!b.empty()) {
        int smallest = *b.begin();
        b.erase(b.begin());
        auto match = a.lower_bound(smallest);
        if (match == a.begin()) continue;
        --match;
        if (*match < smallest) {
            result ++;
            a.erase(match);
        }
    }
    cout << result << endl;
    return 0;
}
