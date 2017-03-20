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
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;

int t, n, x;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        map<int, int> m;
        for(int i = 0; i < n; i ++){
            scanf("%d", &x);
            m[x] ++;
        }
        int ans = 0;
        for(auto i : m)
            if(i.first % 2 == 0 && m.count(i.first / 2))
                ans ++;
        printf("%d\n", ans);
    }
    
    return 0;
}
