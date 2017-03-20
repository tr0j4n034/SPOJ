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
 
const int me = 1000025;
const int fixx = 10;
 
int t, n, x;
long long ft[me];
 
void add(int pos, int value){
    pos += fixx;
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
long long get(int pos){
    pos += fixx;
    long long s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
 
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    /// http://www.spoj.com/problems/TREAP/
    
    scanf("%d", &t);
    while(t --){
        fill(ft, ft + me, 0);
        long long s = 0;
        scanf("%d", &n);
        while(n --){
            scanf("%d", &x);
            s += get(x - 1);
            add(x, x);
        }
        printf("%lld\n", s);
    }
    
    return 0;
} 