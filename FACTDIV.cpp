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
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 1000025;
const int mod = 1000000007;

int T, L, R;
int current;
int prime[me], lp[me], res[me], f[me], cnt[me];

int power(int a, int b){
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * power(a, b - 1) * a % mod;
    int half = power(a, b >> 1);
    return 1LL * half * half % mod;
}
int inverse(int a){
    return power(a, mod - 2);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    res[1] = 1;
    current = 1;
    for(int i = 2; i < me; i ++)
        if(!prime[i]){
            lp[i] = i;
            for(int j = i + i; j < me; j += i)
                prime[j] = 1, lp[j] = i;
        }
    for(int i = 2; i < me; i ++){
        int j = i;
        while(j > 1){
            int d = lp[j];
            int cnt = 0;
            while(j % d == 0){
                cnt ++;
                j /= d;
            }
            current = 1LL * current * inverse(f[d] + 1) % mod;
            f[d] += cnt;
            current = 1LL * current * (f[d] + 1) % mod;
        }
        res[i] = current;
    }
    for(int i = 1; i < me; i ++)
        res[i] = (res[i - 1] + res[i]) % mod;
    
    cin >> T;
    while(T --){
        cin >> L >> R;
        cout << (res[R] - res[L - 1] + mod) % mod << endl;
    }
    
    return 0;
}
