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

const int me = 10025;

int t, n, m;
int a[me], b[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n >> m;
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        for(int i = 0; i < m; i ++)
            cin >> b[i];
        long long l_sum = accumulate(a, a + n, 0LL), r_sum = accumulate(b, b + m, 0LL);
        cout << "Case " << c + 1 << ": " << l_sum + r_sum - max(a[n - 1], b[m - 1]) << endl;
    }
    
    return 0;
}

