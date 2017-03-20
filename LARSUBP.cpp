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

const int me = 10025;
const int mod = 1000000007;

int t, n;
char s[me];
int dp[me][10];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    for(int c = 0; c < t; c ++){
        scanf(" %s", s);
        n = (int)strlen(s);
        for(int i = 0; i < n; i ++)
            s[i] -= '0';
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < 10; j ++)
                dp[i][j] = 0;
        dp[0][s[0]] = 1;
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < s[i]; j ++)
                add(dp[i][s[i]], dp[i - 1][j]);
            add(dp[i][s[i]], 1);
            for(int j = 0; j < 10; j ++)
                add(dp[i][j], dp[i - 1][j]);
        }
        int ans = 0;
        for(int i = 0; i < 10; i ++)
            add(ans, dp[n - 1][i]);
        printf("Case %d: %d\n", c + 1, ans);
    }
    
    return 0;
}