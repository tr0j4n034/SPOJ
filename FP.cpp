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
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 125;

bool IsGreater(string a, string b){
    if((int)a.size() > (int)b.size())
        return true;
    else if((int)a.size() < (int)b.size())
        return false;
    for(int i = 0; i < (int)a.size(); i ++){
        if(a[i] > b[i])
            return true;
        if(a[i] < b[i])
            return false;
    }
    return false;
}
string max(string a, string b){
    if(IsGreater(a, b))
        return a;
    return b;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, k;
    int a[me];
    
    cin >> t;
    while(t --){
        cin >> n >> k;
        for(int i = 0; i < n; i ++)
            cin >> a[i];
         sort(a, a + n, [&](const int a, const int b){
         string f = to_string(a) + to_string(b);
         string s = to_string(b) + to_string(a);
         return IsGreater(f, s);
         });
        string dp[me][9];
        for(int i = 1; i <= k; i ++)
            for(int j = 0; j < 9; j ++)
                dp[i][j] = "0";
        dp[1][a[0] % 9] = to_string(a[0]);
        for(int i = 1; i < n; i ++){
            for(int j = k - 1; j > 0; j --)
                for(int q = 0; q < 9; q ++)
                    if(dp[j][q] != "0")
                        dp[j + 1][(q + a[i]) % 9] = max(dp[j + 1][(q + a[i]) % 9], dp[j][q] + to_string(a[i]));
            if(dp[1][a[i] % 9] == "0" || IsGreater(to_string(a[i]), dp[1][a[i] % 9]))
                dp[1][a[i] % 9] = to_string(a[i]);
        }
        string ans = dp[k][0];
        if(ans == "0")
            cout << -1 << endl;
        else cout << ans << endl;
    }
    
    return 0;
}