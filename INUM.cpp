//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/2/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
long long a[100005];
map<long long, int> m;

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> a[i];
        m[a[i]] ++;
    }
    sort(a, a + N);
    long long delta = 1LL << 55;
    for (int i = 1; i < N; i ++) {
        if (a[i] - a[i - 1] < delta) {
            delta = a[i] - a[i - 1];
        }
    }
    long long minPairs = 0, maxPairs = 0;
    if (a[0] == a[N - 1]) {
        maxPairs = 1LL * m[a[0]] * (m[a[0]] - 1) / 2;
    }
    else {
        maxPairs = 1LL * m[a[0]] * m[a[N - 1]];
    }
    for (int i = 0; i < N; i ++) {
        if(delta == 0 && (i == 0 || a[i] != a[i - 1])) {
            minPairs += 1LL * m[a[i]] * (m[a[i]] - 1) / 2;
        }
        else if(delta > 0 && i > 0 && a[i] - a[i - 1] == delta) {
            minPairs += 1LL * m[a[i]] * m[a[i - 1]];
        }
    }
    cout << minPairs << " " << maxPairs << endl;
    
    return 0;
}
