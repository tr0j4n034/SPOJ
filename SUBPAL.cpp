#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 1000025;
const int sz = 26;

int T;
string s;
vector<int> v[1 << sz];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int cases = 0; cases < T; cases ++){
        cin >> s;
        set<int> active_masks;
        int current_mask = 0;
        active_masks.insert(0);
        v[0].push_back(0);
        for(int i = 0; i < (int)s.size(); i ++){
            current_mask ^= (1 << (s[i] - 'a'));
            active_masks.insert(current_mask);
            v[current_mask].push_back(i + 1);
        }
        int result = 0;
        for(int i : active_masks){
            result = max(result, v[i].back() - v[i].front());
            for(int j = 0; j < 26; j ++){
                int p = i ^ (1 << j);
                if(!v[p].empty()){
                    result = max(result, v[i].back() - v[p].front());
                    result = max(result, v[p].back() - v[i].front());
                }
            }
        }
        cout << "Case " << cases + 1 << ": " << result << endl;
        for(int i : active_masks)
            v[i].clear();
    }
    
    return 0;
}