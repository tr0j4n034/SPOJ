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

const int me = 1025;

int a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;
    
    if(a % b == 0){
        cout << 0 << endl;
        return 0;
    }
    int r1 = 1, r2 = 1, ans = 0;
    for(int i = 1; ; i ++){
        if(r1 == 0 && r2 == 0)
            break;
        r1 = 1LL * r1 * i % a;
        r2 = 1LL * r2 * i % b;
        if(r1 == 0 && r2 != 0)
            ans ++;
    }
    cout << ans << endl;
    
    return 0;
}
