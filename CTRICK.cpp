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

const int me = 30025;

int t, n;
int ft[me], ans[me];

void add(int pos, int value){
    pos += 5;
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    pos += 5;
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
int get(int l, int r){
    return get(r) - get(l - 1);
}
int find(int low, int high, int k){
    if(low == high)
        return low;
    int mid = (low + high) >> 1;
    int s = get(low, mid);
    if(s >= k)
        return find(low, mid, k);
    return find(mid + 1, high, k - s);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        fill(ft, ft + me, 0);
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            add(i, 1);
        int cur_pos = 0;
        for(int i = 2; i <= n + 1; i ++){
            int w = i % (n - i + 2);
            if(w == 0)
                w = n - i + 2;
            int has = get(cur_pos + 1, n);
            if(has >= w){
                cur_pos = find(cur_pos + 1, n, w);
                add(cur_pos, -1);
            }
            else{
                cur_pos = find(1, cur_pos, w - has);
                add(cur_pos, -1);
            }
            ans[cur_pos] = i - 1;
        }
        for(int i = 1; i <= n; i ++){
            printf("%d", ans[i]);
            if(i < n)
                putchar(' ');
        }
        putchar('\n');
    }
    
    
    return 0;
}