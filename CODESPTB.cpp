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

int t, n, x;
int ft[me];

void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    int ans = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        ans += ft[pos];
    return ans;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        fill(ft, ft + me, 0);
        long long ans = 0;
        for(int i = 0; i < n; i ++){
            scanf("%d", &x);
            ans += i - get(x + 5);
            add(x + 5, 1);
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}