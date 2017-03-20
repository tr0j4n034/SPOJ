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

const int me = 100025;
const int oo = 1 << 30;

int t, n;
int ft[me];
pair<int, pair<int, int>> a[me];

void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] = min(ft[pos], value);
}
int get(int pos){
    int ans = oo;
    for( ; pos > 0; pos -= (pos & -pos))
        ans = min(ans, ft[pos]);
    return ans;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d%d%d", &a[i].first, &a[i].second.first, &a[i].second.second);
        sort(a, a + n);
        fill(ft, ft + me, oo);
        int ans = 0;
        for(int i = 0; i < n; i ++){
            int g = get(a[i].second.first + 5);
            if(g > a[i].second.second)
                ans ++;
            add(a[i].second.first + 5, a[i].second.second);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}