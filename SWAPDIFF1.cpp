//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 100005;

int T, N;
int a[MAX];
int ftree[MAX];

void add(int position, int value) {
    for ( ; position < MAX; position += (position & -position)) {
        ftree[position] += value;
    }
}
int get(int position) {
    int s = 0;
    for ( ; position > 0; position -= (position & -position)) {
        s += ftree[position];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T --) {
        cin >> N;
        for (int i = 1; i <= N; i ++) cin >> a[i];
        for (int i = 1; i <= N; i ++) ftree[i] = 0;
        long long inversions = 0;
        for (int i = 1; i <= N; i ++) {
            inversions += i - 1 - get(a[i]);
            add(a[i], 1);
        }
        cout << inversions << endl;
    }
    
    return 0;
}
