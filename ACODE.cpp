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

const int me = 5025;

string s;
long long dp[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> s){
        if(s == "0")
            break;
        int n = (int)s.size();
        for(int i = 0; i <= n; i ++)
            dp[i] = 0;
        s = "$" + s;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i ++){
            if(s[i] != '0')
                dp[i] = dp[i - 1];
            int last = 10 * (s[i - 1] - '0') + s[i] - '0';
            if(s[i - 1] != '0' && last >= 1 && last <= 26)
                dp[i] += dp[i - 2];
        }
        cout << dp[n] << endl;
    }
    
    return 0;
}

