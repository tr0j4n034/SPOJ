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
int cnt[32];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n;
        for(int i = 0; i < 32; i ++)
            cnt[i] = 0;
        for(int i = 0; i < n; i ++){
            int x;
            cin >> x;
            for(int j = 0; j < 32; j ++)
                if(x & (1 << j))
                    cnt[j] ++;
        }
        int ans = 0;
        for(int i = 0; i < 32; i ++)
            ans = (ans + 1LL * cnt[i] * (n - cnt[i]) % 10000007) % 10000007;
        ans = (2LL * ans) % 10000007;
        cout << "Case " << c + 1 << ": " << ans << endl;
    }
    
    return 0;
}

