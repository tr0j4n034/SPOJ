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

const int me = 50025;

int t, n;
int a[me], ft[me];

void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        fill(ft, ft + me, 0);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
            add(a[i], 1);
        }
        long long ans = 0;
        for(int i = 1; i <= n; i ++)
            ans += get(a[i]);
        printf("%lld\n", ans);
    }
    
    return 0;
}
