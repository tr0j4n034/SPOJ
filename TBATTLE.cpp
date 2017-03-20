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
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;
const int MAX_LOG = 20;

int n;
int a[me], st[me][MAX_LOG];

int get(int l, int r){
    int s = 1;
    for(int i = MAX_LOG; i >= 0; i --){
        if(l + (1 << i) - 1 <= r){
            s = 1LL * s * st[l][i] % n;
            l += 1 << i;
        }
    }
    return s;
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++)
        st[i][0] = a[i] % n;
    for(int j = 1; j < MAX_LOG; j ++)
        for(int i = 1; i + (1 << j) - 1 <= n; i ++)
            st[i][j] = 1LL * st[i][j - 1] * st[i + (1 << (j - 1))][j - 1] % n;
    int ans = n + 1, pos = n + 1;
    for(int i = 1; i <= n; i ++){
        if(get(i, n) != 0)
            continue;
        int low = i, high = n, mid, best = n;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            if(get(i, mid) == 0){
                best = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(best - i + 1 < ans){
            ans = best - i + 1;
            pos = i;
        }
    }
    if(ans == n + 1)
        cout << -1 << endl;
    else cout << pos - 1 << " " << pos + ans - 2 << endl;
    
    return 0;
}
