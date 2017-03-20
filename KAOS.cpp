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

int n;
int ft[me], pos[me];
pair<string, int> a[me], b[me];

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> a[i].first;
    for(int i = 0; i < n; i ++){
        a[i].second = i;
        b[i].second = i;
        b[i].first = a[i].first;
        reverse(b[i].first.begin(), b[i].first.end());
    }
    sort(a, a + n);
    sort(b, b + n);
    //for(int i = 0; i < n; i ++)
      //  cout << b[i].first << " " << b[i].second << endl;
    for(int i = 0; i < n; i ++)
        pos[b[i].second] = i;
    for(int i = 0; i < n; i ++)
        add(pos[i], 1);
    //for(int i = 0; i < n; i ++)
      //  cout << i << " " << pos[i] << endl;
    long long ans = 0;
    for(int i = 0; i < n; i ++){
        ans += get(pos[a[i].second] - 1);
        add(pos[a[i].second], -1);
    }
    cout << ans << endl;
    
    return 0;
}