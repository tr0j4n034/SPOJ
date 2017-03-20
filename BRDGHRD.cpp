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

const int me = 100025;

int t, n;
pair<int, int> a[me];
int ft[me], dp[me];

void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] = max(ft[pos], value);
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s = max(s, ft[pos]);
    return s;
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i].first);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i].second);
        sort(a, a + n);
        map<int, int> c, pos;
        for(int i = 0; i < n; i ++)
            c[a[i].second] = 1;
        int ptr = 1;
        for(map<int, int> :: iterator it = c.begin(); it != c.end(); it ++)
            pos[(*it).first] = ++ptr;
        for(int i = 0; i < n; i ++)
            a[i].second = pos[a[i].second];
        fill(ft, ft + me, 0);
        for(int i = 0; i < n; i ++){
            dp[i] = get(a[i].second) + 1;
            add(a[i].second, dp[i]);
        }
        printf("%d\n", *max_element(dp, dp + n));
    }
    
    return 0;
}