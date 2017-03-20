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
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;

int t;
unsigned long long n;

unsigned long long f(long long n){
    if(n % 2 == 0)
        return n / 2 * (n + 1);
    else return (n + 1) / 2 * n;
}
long long get(long long n){
    long long sum = 0;
    for(long long i = 2; i <= n; i ++){
        for(long long j = 1; j < i; j ++)
            if(i % j == 0)
                sum += j;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> t;
    while(t --){
        cin >> n;
        long long sum = 0, up = n - 1;
        for(int i = 1; 1LL * i * i <= n; i ++){
            long long now = n / i;
            long long before = n / (i + 1);
            sum += 1LL * i * (f(now) - f(before));
            up = before;
        }
        for(long long i = 1; i <= up; i ++)
            sum += n / i * i;
        cout << sum - f(n) << endl;
    }
    
    return 0;
}
