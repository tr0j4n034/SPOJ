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

const int me = 265;
const int sz = 10;
const int mod = 1000000007;

struct matrix{
    int a[sz][sz];
    matrix(){
        for(int i = 0; i < sz; i ++)
            for(int j = 0; j < sz; j ++)
                a[i][j] = 0;
    }
};
matrix mul(matrix a, matrix b, int d){
    matrix c;
    for(int i = 0; i < sz; i ++)
        for(int j = 0; j < sz; j ++)
            if(a.a[i][j])
                for(int k = 0; k < sz; k ++)
                    if(abs(k - j) >= d)
                        for(int q = 0; q < sz; q ++)
                            c.a[i][q] = (c.a[i][q] + 1LL * a.a[i][j] * b.a[k][q] % mod) % mod;
    return c;
}
matrix bin_pow(matrix a, int b, int d){
    matrix res = a; b --;
    for( ; b > 0; b >>= 1){
        if(b & 1)
            res = mul(res, a, d);
        a = mul(a, a, d);
    }
    return res;
}
int bin_pow(int a, int b, int mod){
    if(b == 0)
        return 1 % mod;
    if(b & 1)
        return 1LL * bin_pow(a, b - 1, mod) * a % mod;
    int half = bin_pow(a, b >> 1, mod);
    return 1LL * half * half % mod;
}

int t, n, k;
matrix a;

int good(int n, int d){
    int last = n % 10;
    n /= 10;
    while(n > 0){
        int r = n % 10;
        n /= 10;
        if(abs(r - last) < d)
            return 0;
        last = r;
    }
    return 1;
}
int get(int n, int k){
    int low = 1;
    for(int i = 1; i < n; i ++)
        low *= 10;
    int s = 0;
    for(int i = low; i < low * 10; i ++){
        if(good(i, k))
            s ++;
    }
    return s;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> n >> k;
        if(k == 0){
            cout << 9LL * bin_pow(10, n - 1, mod) % mod << endl;
            continue;
        }
        for(int i = 0; i < sz; i ++)
            for(int j = 0; j < sz; j ++)
                a.a[i][j] = 0;
        for(int i = 0; i < sz; i ++)
            a.a[i][i] = 1;
        a = bin_pow(a, n, k);
        int ans = 0;
        for(int i = 1; i < sz; i ++)
            for(int j = 0; j < sz; j ++)
                ans = (ans + a.a[i][j]) % mod;
        cout << ans << endl;
    }
    
    return 0;
}
