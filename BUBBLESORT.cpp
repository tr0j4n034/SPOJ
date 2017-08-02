//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/2/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10005;

int T, N;
int data[MAX], ft[MAX];

void add(int position) {
    for ( ; position < MAX; position += (position & -position)) {
        ft[position] ++;
    }
}
int get(int position) {
    int sum = 0;
    for ( ; position > 0; position -= (position & -position)) {
        sum += ft[position];
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    for (int c = 0; c < T; c ++) {
        cin >> N;
        for(int i = 1; i <= N; i ++) {
            cin >> data[i];
        }
        vector<int> values = vector<int> (data + 1, data + N + 1);
        sort(values.begin(), values.end());
        for (int i = 1; i <= N; i ++) {
            data[i] = (int)(lower_bound(values.begin(), values.end(), data[i]) - values.begin()) + 1;
        }
        fill(ft, ft + MAX, 0);
        int result = 0;
        for (int i = 1; i <= N; i ++) {
            result = (result + i - 1 - get(data[i])) % 10000007;
            add(data[i]);
        }
        cout << "Case " << c + 1 << ": " << result << endl;
    }
    
    return 0;
}
