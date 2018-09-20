//
//  main.cpp
//  practice
//
//  Created by Mahmud on 20/9/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(N * log(N)) solution using STL sets and maps
 */

#include <iostream>
#include <set>
#include <map>

using namespace std;

int Q;
set<int> costs;
map<int, string> items;
map<string, int> itemData; // for

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> Q;
    for (int i = 0; i < Q; i ++) {
        int type, cost;
        string name;
        cin >> type;
        if (type == 1) {
            cin >> name >> cost;
            costs.insert(cost);
            items[cost] = name;
            itemData[name] = cost;
        } else if (type == 2) {
            cin >> name >> cost;
            costs.erase(itemData[name]);
            costs.insert(cost);
            items[cost] = name;
            itemData[name] = cost;
        } else {
            cin >> name;
            int smallestCost = *(costs.begin());
            costs.erase(smallestCost);
            cout << items[smallestCost] << " " << i + 1 << endl;
        }
    }
    
    return 0;
}

