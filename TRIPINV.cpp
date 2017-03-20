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
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;

int n, x;
long long ans;
int a[me];
long long ft[3][me];

void add(long long *ft, int pos, long long value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
long long get(long long *ft, int pos){
    long long s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    reverse(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++){
        x = a[i];
        add(ft[2], x, ans += get(ft[1], x - 1));
        add(ft[1], x, get(ft[0], x - 1));
        add(ft[0], x, 1);
    }
    cout << ans << endl;
    
    return 0;
}
