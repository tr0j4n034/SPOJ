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
 
const int me = 200025;
const int fixx = 100003;
 
int n, q, type, x, l, r;
long long ft[me];
 
void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
long long get(int pos){
    long long s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    /// http://www.spoj.com/problems/TREAP/
    
    scanf("%d", &n);
    int free_slot = fixx;
    for(int i = 1; i <= n; i ++){
        scanf("%d", &x);
        add(i + free_slot, x);
    }
    scanf("%d", &q);
    while(q --){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d%d", &l, &r);
            printf("%lld\n", get(r + free_slot) - get(l + free_slot - 1));
        }
        else{
            scanf("%d", &x);
            add(free_slot --, x);
        }
    }
    
    return 0;
} 