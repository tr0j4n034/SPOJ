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

const int me = 125;


long long pw[me];

long long get(long long n, int p){
    long long all = pw[p + 1];
    long long half = pw[p];
    return n / all * half + (n % all >= half ? n % all - half + 1 : 0);
}
long long get(long long n){
    long long total = 0;
    for(int i = 46; i >= 0; i --)
        total += get(n, i);
    return total;
}
long long solve(long long n){
    long long low = 1, high = 1LL << 46, mid, s = -1;
    while(low <= high){
        mid = (low + high + 1) >> 1;
        long long total = get(mid);
        if(total == n){
            s = mid;
            break;
        }
        if(total > n){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return s;
}
static long long uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    long long n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    pw[0] = 1;
    for(int i = 1; i < 50; i ++)
        pw[i] = pw[i - 1] << 1;
    
    int t;
    long long n;
    
    scanf("%d", &t);
    while(t --){
        scanf("%lld", &n);
        //long long s = solve(n);
        int bits = 0;
        long long ans = 0;
        for(int i = 46; i >= 0; i --){
            long long skip = i > 0 ? 1LL * i * pw[i - 1] : 0;
            long long extra = 1LL * bits * (pw[i] - 1) + bits + 1;
            //cout << "i = " << i << ", n = " << n << ", skip = " << skip << ", extra = " << extra << endl;
            if(n >= skip + extra){
                ans |= 1LL << i;
                n -= skip + extra;
                bits ++;
            }
        }
        //cout << ans << " vs " << n << endl;
        //if(s == -1)
          //  puts("Does Not Exist.");
        //else printf("%lld\n", s);
        if(n == 0)
            printf("%lld\n", ans);
        else puts("Does Not Exist.");
    }
    
    return 0;
}
