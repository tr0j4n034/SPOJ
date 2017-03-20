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
#include <unordered_set>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 2025;

int N, C;
int a[me];
map<int, int> m, pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> C;
    for(int i = 0; i < N; i ++){
        cin >> a[i];
        if(!pos.count(a[i]))
            pos[a[i]] = i;
        m[a[i]] ++;
    }
    vector<pair<int, int>> v;
    for(auto i : m)
        v.push_back(make_pair(i.second, i.first));
    
    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b){
        if(a.first != b.first)
           return a.first > b.first;
        return pos[a.second] < pos[b.second];
    });
    
    int done = 0;
    for(auto i : v){
        for(int j = 0; j < i.first; j ++){
            cout << i.second;
            done ++;
            if(done < N)
                cout << " ";
        }
    }
    cout << endl;
 
    return 0;
}
