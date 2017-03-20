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

int t;
long long n;
int cnt[me];
map<long long, int> m;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 1; i < me; i ++){
        long long d = 1;
        int now = i;
        for(int j = 2; j * j <= now; j ++)
            if(now % j == 0){
                while(now % j == 0)
                    now /= j, cnt[j] ++;
            }
        if(now > 1)
            cnt[now] ++;
        for(int j = 2; j <= i; j ++)
            d *= cnt[j] + 1;
        if(!m[d])
            m[d] = i;
    }
    
    scanf("%d", &t);
    while(t --){
        scanf("%lld", &n);
        if(m.count(n))
            printf("%d\n", m[n]);
        else puts("nai");
    }
    
    return 0;
}
