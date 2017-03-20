#include<iostream>
#include <list>
#include <stack>
#include <vector>
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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 2025;

int t, n;
int a[me], b[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        for(int i = 0; i < n; i ++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        int ans = 0;
        for(int i = 0; i < n; i ++)
            ans += a[i] * b[i];
        cout << ans << endl;
    }
    
    return 0;
}

