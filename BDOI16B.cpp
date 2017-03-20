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

const int me = 100025;

/// http://www.spoj.com/problems/BDOI16D/

long long get(int n, int k){
    long long sum = 0;
    for(long long i = k; i <= n; i *= k)
        sum += n / i;
    return sum;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("arrayfactory.in", "r", stdin);
    //freopen("arrayfactory.out", "w", stdout);
    
    int t, n, k;
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n >> k;
        long long ans = 1LL << 55;
        for(int i = 2; i * i <= k; i ++){
            if(k % i == 0){
                int cnt = 0;
                while(k % i == 0){
                    cnt ++;
                    k /= i;
                }
                ans = min(ans, get(n, i) / cnt);
            }
        }
        if(k > 1)
            ans = min(ans, get(n, k));
        cout << "Case " << c + 1 << ": " << ans << endl;
    }
    
    return 0;
}

