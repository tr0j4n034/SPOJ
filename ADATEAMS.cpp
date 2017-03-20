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

const int me = 1000025;
const int mod = 1000000007;

int N, A, B, D;
int fac[me], inv[me];

int bin_pow(int a, int b){
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * bin_pow(a, b - 1) * a % mod;
    int half = bin_pow(a, b >> 1);
    return 1LL * half * half % mod;
}
int comb(int n, int k){
    return 1LL * fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < me; i ++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
        inv[i] = bin_pow(fac[i], mod - 2);
    }
    
    while(scanf("%d%d%d%d", &N, &A, &B, &D) != EOF){
        int result = 1LL * comb(N, A) * bin_pow(comb(B, D), A) % mod;
        printf("%d\n", result);
    }
    
    return 0;
}
