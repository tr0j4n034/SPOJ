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

const int me = 10025;

struct order{
    int start;
    int end;
    int price;
    order() {}
    order(int start, int end, int price) : start(start), end(end), price(price) {}
    bool operator < (const order other)const{
        if(end != other.end)
            return end < other.end;
        return start < other.start;
    }
};

int t, n;
order a[me];
long long dp[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%d%d%d", &a[i].start, &a[i].end, &a[i].price);
            a[i].end += a[i].start;
        }
        sort(a + 1, a + n + 1);
        //for(int i = 1; i <= n; i ++)
          //  cout << a[i].start << " vs " << a[i].end << endl;
        dp[1] = a[1].price;
        for(int i = 2; i <= n; i ++){
            dp[i] = dp[i - 1];
            auto pos = upper_bound(a + 1, a + n + 1, order(a[i].start - 1, a[i].start - 1, 0)) - (a + 1);
            //cout << i << " --> " << "pos = " << pos << endl;
            dp[i] = max(dp[i], dp[pos] + a[i].price);
        }
        printf("%lld\n", *max_element(dp + 1, dp + n + 1));
    }
 
    return 0;
}