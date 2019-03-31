//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/31/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> s;

int main(int argc, const char* argv[]) {
    cin >> N;
    auto isMatch = [&](stack<int> &brackets, int value) {
        if (brackets.empty()) return false;
        return value && brackets.top() == -value;
    };
    for (int i = 0; i < N; i ++) {
        int x; cin >> x;
        if (isMatch(s, x)) s.pop();
        else s.push(x);
    }
    cout << int(s.size()) << endl;
    
    return 0;
}
