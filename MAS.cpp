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

const int me = 100025;
const long long mod = 2760727302517LL;

int T, N, Q;
int type, x, v;
long long sum, square_sum;
long long a[me];

long long mul(long long a, long long b){
    if(b == 0)
        return 0;
    if(b & 1)
        return (mul(a, b - 1) + a) % mod;
    long long half = mul(a, b >> 1);
    return (half + half) % mod;
}

void add(int pos, long long value){
    value %= mod;
    sum = (sum + mod - a[pos]) % mod;
    sum = (sum + value) % mod;
    square_sum = (square_sum + mod - mul(a[pos], a[pos])) % mod;
    square_sum = (square_sum + mul(value, value)) % mod;
    a[pos] = value;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
/*
 (n - 1) * (a1^2 + a2^2 + ... + an^2) - 2 * (a1*a2+a1*a3+...) = 
 (n - 1) * (a1^2 + ... + an^2) - (a1 + a2 + a3 + ... + an)^2 + (a1^2 + a2^2+...) =
 n * (a1^2 + a2^2 + ... + an^2) - (a1+a2+..+an)^2
 */
    
    scanf("%d", &T);
    for(int cases = 0; cases < T; cases ++){
        scanf("%d%d", &N, &Q);
        for(int i = 1; i <= N; i ++)
            scanf("%lld", &a[i]);
        
        sum = 0, square_sum = 0;
        for(int i = 1; i <= N; i ++){
            sum = (sum + a[i]) % mod;
            square_sum = (square_sum + a[i] * a[i]) % mod;
        }
        
        printf("Case %d:\n", cases + 1);
        
        while(Q --){
            scanf("%d", &type);
            if(type == 1){
                scanf("%d%d", &x, &v);
                add(x, v);
            }
            else if(type == 2){
                scanf("%d%d", &x, &v);
                add(x, a[x] + v);
            }
            else{
                long long result = (1LL * N * square_sum % mod - mul(sum, sum) + mod) % mod;
                printf("%lld\n", result);
            }
        }
    }
    
    return 0;
}
