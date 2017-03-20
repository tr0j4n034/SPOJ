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
matrix power(matrix a, int b){
    if(b == 1)
        return a;
    if(b & 1)
        return mul(power(a, b - 1), a);
    matrix half = power(a, b >> 1);
    return mul(half, half);
}
int power(int a, int b){
    if(b == 0)
        return 1 % mod;
    if(b & 1)
        return 1LL * power(a, b - 1) * a % mod;
    int half = power(a, b >> 1);
    return 1LL * half * half % mod;
}

long long fib[me];

int Kth_non_fib(int k){
    int low = 1, high = mod, mid, best = high;
    while(low <= high){
        mid = (low + high + 1) >> 1;
        int sum = 0;
        for(int i = 2; i < me; i ++){
            if(fib[i] <= mid)
                sum ++;
        }
        if(mid - sum >= k){
            best = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return best;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i < me; i ++)
        fib[i] = fib[i - 1] + fib[i - 2];
    
    int t, n, a, b;
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        matrix fib;
        fib.a[0][0] = 1, fib.a[0][1] = 1;
        fib.a[1][0] = 1, fib.a[1][1] = 0;
        fib = power(fib, n);
        a = fib.a[0][1];
        b = Kth_non_fib(n);
        printf("%d\n", power(b, a));
    }
    
    return 0;
}
