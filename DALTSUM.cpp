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

const int me = 100025;
const int mod = 1000000007;

int n;
long long a[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    long long m = *max_element(a, a + n);
    m %= mod;
    if(m < 0)
        m += mod;
    for(int i = 1; i < n; i ++)
        m = m * 2 % mod;
    cout << m << endl;
    
    return 0;
}

