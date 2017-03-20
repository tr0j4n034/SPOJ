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
 
const int me = 300025;
 
int t, n;
long long p;
long long a[me];
map<long long, int> m;
 
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        m.clear();
        for(int i = 0; i < n; i ++)
            scanf("%lld", &a[i]);
        scanf("%lld", &p);
        for(int i = 0; i < n; i ++)
            m[a[i]] ++;
        int ok = 0;
        for(int i = 0; i < n && !ok; i ++){
            m[a[i]] --;
            for(int j = i + 1; j < n && !ok; j ++){
                m[a[j]] --;
                if(m[p - a[i] - a[j]] > 0)
                   ok = 1;
                m[a[j]] ++;
            }
            m[a[i]] ++;
        }
        if(ok)
            puts("YES");
        else puts("NO");
    }
    
    return 0;
} 