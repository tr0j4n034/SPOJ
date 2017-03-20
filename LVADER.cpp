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
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 200025;
const int mod = 1000000007;

int T;
int x[2], y[2], fac[me], inv[me];

int bin_pow(int a, int b){
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * bin_pow(a, b - 1) * a % mod;
    int half = bin_pow(a, b >> 1);
    return 1LL * half * half % mod;
}
int binom(int n, int k){
    return 1LL * fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    fac[0] = 1;
    for(int i = 1; i < me; i ++)
        fac[i] = 1LL * fac[i - 1] * i % mod;
    for(int i = 0; i < me; i ++)
        inv[i] = bin_pow(fac[i], mod - 2);
    
    cin >> T;
    for(int cases = 0; cases < T; cases ++){
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        
        int dx = x[1] - x[0];
        int dy = y[1] - y[0];
        int all = dx + dy;
        
        int answer = 0;
        for(int i = 0; i <= min(dx, dy); i ++){
            int d = all - i - i;
            int add = 1LL * binom(d, dx - i) * binom(d + i, i) % mod;
            answer = (answer + add) % mod;
        }
        
        cout << "Case " << cases + 1 << ": " << answer << endl;
    }
    
    return 0;
}
