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
 
const int me = 10025;
const long double eps = 1.e-12;
 
int T, K;
long double p;
long double fac[me], dp[me][me];
 
long double comb(int n, int k){
    return fac[n] / fac[k] / fac[n - k];
}
long double power(double a, int b){
    if(b == 0)
        return 1.;
    if(b & 1)
        return power(a, b - 1) * a;
    long double half = power(a, b >> 1);
    return half * half;
}
long double get(int tosses, int K, long double p){
    return comb(tosses, K) * power(p, K) * power(1. - p, tosses - K);
}
 
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    /*
    fac[0] = 1.;
    for(int i = 1; i < me; i ++)
        fac[i] = fac[i - 1] * i;
    
    int k = 3;
    for(int i = k; i < 10; i ++){
        double f = comb(i, k);
        cout << f << " vs " << f * 1. * (i + 1) / (i - k + 1) << endl;
    }
    */
    /*
     n! / k! / (n - k)!
     (n + 1) ! / k! / (n - k + 1) ! =
     = n! * (n + 1) / k! / (n - k)! / (n - k + 1)
     */
    
    cin >> T;
    
    while(T --){
        cin >> K >> p;
        /*
        dp[0][0] = 1.;
        for(int i = 1; i < me; i ++)
            for(int j = 0; j <= i && j <= K; j ++){
                dp[i][j] = dp[i - 1][j] * (1. - p);
                if(j > 0)
                    dp[i][j] += dp[i - 1][j - 1] * p;
            }
        cout.precision(10);
        for(int i = K; i < 10; i ++)
            cout << "i = " << i << " --> " << fixed << dp[i][K] << " vs " << get(i, K, p) << endl;
        int pos = 1;
        for(int i = 1; i < me; i ++)
            if(dp[i][K] > dp[pos][K])
                pos = i;
        cout << pos << endl;
        */
        
        /*
        int pos = K;
        long double s = get(K, K, p);
        for(int i = K + 1; i < me; i ++){
            long double res = get(i, K, p);
            if(res > s + eps){
                s = res;
                pos = i;
            }
        }
        cout << pos << endl;
        */
        
        int pos = K;
        double now = 1., best = now;
        for(int i = K + 1; i < me; i ++){
            now = now * 1. * i / (i - K) * (1. - p);
            if(now > best + eps){
                best = now;
                pos = i;
            }
        }
        cout << pos << endl;
    }
    
    return 0;
}