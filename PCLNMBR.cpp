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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1000025;

int a, b, c, m, n;
int lcm1, lcm2;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d%d%d", &a, &b, &c, &m);
    lcm1 = a * b / __gcd(a, b);
    lcm2 = lcm1 * c / __gcd(lcm1, c);
    while(m --){
        scanf("%d", &n);
        long long low = 1, high = 1LL << 60, mid, best = high;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            long long has = mid / a - mid / lcm1 + mid / lcm2;
            if(has >= n){
                best = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        printf("%lld\n", best);
    }
    
    return 0;
}