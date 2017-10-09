//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/9/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100025;

int T, N;
int data[MAX];

int main() {
    scanf("%d", &T);
    while (T --) {
        cin >> N;
        int result = 0;
        for (int i = 1; i <= N; i ++) {
            cin >> data[i];
            if (data[i] + i - 1 > result) {
                result = data[i] + i - 1;
            }
        }
        cout << result << endl;
    }
    
    return 0;
}
