//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/1/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int jewelCount, bagCount;
int capacity[300005];
vector<pair<int, int>> jewel;

int main(int argc, const char * argv[]) {
    scanf("%d%d", &jewelCount, &bagCount);
    for(int i = 0; i < jewelCount; i ++) {
        int weight, value;
        scanf("%d%d", &weight, &value);
        jewel.push_back(make_pair(weight, value));
    }
    for(int i = 0; i < bagCount; i ++) {
        scanf("%d", &capacity[i]);
    }
    sort(jewel.begin(), jewel.end());
    sort(capacity, capacity + bagCount);
    
    long long result = 0;
    int ptr = 0;
    multiset<int> candidates;
    for(int i = 0; i < bagCount; i ++) {
        while(ptr < jewelCount && jewel[ptr].first <= capacity[i]) {
            candidates.insert(jewel[ptr].second);
            ptr ++;
        }
        if(!candidates.empty()) {
            int highest = *(--candidates.end());
            result += highest;
            candidates.erase(candidates.find(highest));
        }
    }
    printf("%lld\n", result);
    
    return 0;
}
