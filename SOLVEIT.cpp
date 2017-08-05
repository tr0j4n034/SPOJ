//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/5/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int N, Q;
int type, x;
set<int> s;

int main(int argc, const char * argv[]) {
    scanf("%d%d", &N, &Q);
    while (Q --) {
        scanf("%d%d", &type, &x);
        if (type == 1) {
            s.insert(x);
        }
        else {
            auto it = s.lower_bound(x);
            if (it == s.end()) {
                puts("-1");
            }
            else {
                printf("%d\n", *it);
            }
        }
    }
    
    return 0;
}
