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

const int me = 100025;


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    long long n;
    
    while(scanf("%lld", &n) != EOF){
        if(n == -1)
            break;
        long long a = 1, m = n;
        map<long long, int> div_count;
        for(long long i = 2; i * i * i <= n; i ++){
            if(n % i == 0){
                while(n % i == 0){
                    div_count[i] ++;
                    n /= i;
                }
            }
        }
        if(n > 1){
            long long sq = (long long)sqrt(n + 1.e-9);
            if(sq * sq == n){
                div_count[sq] += 2;
            }
            else{
                div_count[n] ++;
            }
        }
        for(auto &i : div_count){
            while(i.second > 1){
                a *= i.first;
                i.second -= 2;
            }
        }
        printf("%lld %lld\n", a, m / a / a);
    }
    
    return 0;
}
