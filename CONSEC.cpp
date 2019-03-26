//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/26/19.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 O(T * Q * log(N)) solution via STL sets
 Assume that you have [ordered] ranges of consecutive same letters.
 To update and answer queries, you can find the corresponding range via
    lower_bound or upper_bound, then work on it.
 */

#pragma GCC optimize ("O3")

#include <iostream>
#include <cstring>
#include <set>
#include <utility>

using namespace std;

int T, Q;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for (int c = 0; c < T; c ++) {
        string text;
        cin >> text;
        cin >> Q;
        set<pair<int, int>> ranges;
        int lastID = 0;
        for (int i = 0; i < int(text.size()); i ++) {
            if (text[i] != text[lastID]) {
                ranges.insert(make_pair(lastID, i - 1));
                lastID = i;
            }
        }
        ranges.insert(make_pair(lastID, int(text.size()) - 1));
        
        cout << "Case " << c + 1 << ":" << endl;
        while (Q --) {
            int type, position;
            cin >> type >> position;
            if (type == 1) {
                auto it = --ranges.upper_bound(make_pair(position,  1 << 30));
                cout << ((*it).second - (*it).first + 1) << endl;
            } else {
                auto it = --ranges.upper_bound(make_pair(position, 1 << 30));
                int l = (*it).first, r = (*it).second;
                ranges.erase(it);
                if (l != position) ranges.insert(make_pair(l, position - 1));
                if (r != position) ranges.insert(make_pair(position + 1, r));
            }
        }
    }
    
    return 0;
}
