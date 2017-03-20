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
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1000025;
const int MAGIC = 47;

int t, n;
int a[me];


inline int inp()
{
    int n = 0;
    int ch = getchar();int sign = 1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign = -1; ch=getchar();}
    
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
    return n*sign;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    t = inp();
    while(t --){
        n = inp();
        for(int i = 0; i < n; i ++)
            a[i] = inp();
        long long s = 0, sum = 0;
        map<long long, int> m;
        m[0] = 1;
        for(int i = 0; i < n; i ++){
            sum += a[i];
            m[sum] ++;
            if(m.count(sum - MAGIC))
                s += m[sum - MAGIC];
        }
        printf("%lld\n", s);
    }
    
    return 0;
}