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

const int me = 75;
const int mod = 1000000007;

struct matrix{
    int a[2][2];
    matrix() {
        for(int i = 0; i < 2; i ++)
            for(int j = 0; j < 2; j ++)
                a[i][j] = 0;
    }
};

matrix mul(matrix a, matrix b){
    matrix c;
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 2; j ++)
            c.a[i][j] = 0;
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 2; j ++)
            for(int k = 0; k < 2; k ++)
                c.a[i][j] = (c.a[i][j] + 1LL * a.a[i][k] * b.a[k][j] % mod) % mod;
    return c;
}
matrix power(matrix a, long long b){
    if(b == 1)
        return a;
    if(b & 1)
        return mul(power(a, b - 1), a);
    matrix half = power(a, b >> 1);
    return mul(half, half);
}



int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    int t, a, b;
    long long n;
    scanf("%d", &t);
    while(t --){
        scanf("%lld", &n);
        matrix fib;
        fib.a[0][0] = 1, fib.a[0][1] = 1;
        fib.a[1][0] = 1, fib.a[1][1] = 0;
        fib = power(fib, n * 2);
        int a = fib.a[0][0];
        int b = fib.a[0][1];
        printf("%d\n", (int)(1LL * a * b % mod));
    }
    
    return 0;
}
