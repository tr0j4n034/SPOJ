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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1025;

int n, m, x, y;
bitset<me> bs[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &m);
    while(m --){
        scanf("%d%d", &x, &y);
        bs[x].set(y);
    }
    long long ans = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; j <= n; j ++){
            int g = (int)((bs[i] & bs[j]).count());
            ans += g * (g - 1) / 2;
        }
    cout << ans << endl;
    
    return 0;
}
