#include<iostream>
#include <list>
#include <stack>
#include <vector>
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
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 10025;

int t, n;
long long d;
vector<int> v[2];

map<long long, int> get(vector<int> &v){
    map<long long, int> m;
    int l = (int)v.size();
    vector<long long> mask_weight(1 << l, 0LL);
    for(int i = 1; i < (1 << l); i ++){
        for(int j = 0; j < l; j ++)
            if(i & (1 << j)){
                mask_weight[i] = mask_weight[i ^ (1 << j)] + v[j];
                int cur = __builtin_popcount(i);
                if(m[mask_weight[i]] == -2)
                    break;
                if(m[mask_weight[i]] != 0 && m[mask_weight[i]] != cur){
                    m[mask_weight[i]] = -2;
                }
                else{
                    m[mask_weight[i]] = cur;
                }
                break;
            }
    }
    if(m.count(0))
        m[0] = -2;
    else m[0] = 0;
    
    return m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n >> d;
        int half = (n + 1) >> 1;
        v[0].clear();
        v[1].clear();
        for(int i = 0; i < n; i ++){
            int x;
            cin >> x;
            if(i < half)
                v[0].push_back(x);
            else v[1].push_back(x);
        }
        auto m1 = get(v[0]);
        auto m2 = get(v[1]);
        long long can = 0;
        int ans = -1;
        for(auto i : m1){
            if(can == 2)
                break;
            long long need = d - i.first;
            if(m2.count(need)){
                if(i.second == -2 || m2[need] == -2){
                    can = 2;
                    break;
                }
                int cur = i.second + m2[need];
                if(ans != -1 && ans != cur){
                    can = 2;
                    break;
                }
                ans = cur;
                can = 1;
            }
        }
        cout << "Case #" << c + 1 << ": ";
        if(!can)
            cout << "IMPOSSIBLE" << endl;
        else if(can == 1)
            cout << ans << endl;
        else cout << "AMBIGIOUS" << endl;
    }
    
    return 0;
}

