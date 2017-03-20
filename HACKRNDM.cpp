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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1000025;

int n, k, x;
long long s;
map<int, int> m;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++){
        scanf("%d", &x);
        m[x] ++;
    }
    for(auto i : m){
        if(m.count(i.first - k))
            s += 1LL * i.second * m[i.first - k];
    }
    printf("%lld\n", s);
    
    return 0;
}