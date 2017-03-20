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
const int mod = 1000000007;
 
int s, n;
int a[5][5];
vector<int> v[10];
int dp[me][10];
 
void dfs(int x, int step){
    if(step == n){
        s ++;
        return;
    }
    for(int i : v[x])
        dfs(i, step + 1);
}
 
int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 3; j ++)
            a[i][j] = i * 3 + j - 3;
    a[4][1] = 0;
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 3; j ++)
            if(a[i][j] < 10){
                int x = a[i][j];
                if(i - 1 > 0)
                    v[x].push_back(a[i - 1][j]);
                if(i + 1 < 5 && a[i + 1][j] < 10)
                    v[x].push_back(a[i + 1][j]);
                if(j - 1 > 0)
                    v[x].push_back(a[i][j - 1]);
                if(j + 1 < 4 && a[i][j + 1] < 10)
                    v[x].push_back(a[i][j + 1]);
            }
    for(int i = 0; i < 10; i ++)
        dp[1][i] = 1;
    
    for(int i = 1; i < me; i ++)
        for(int j = 0; j < 10; j ++)
            for(int k : v[j]){
                dp[i + 1][k] += dp[i][j];
                dp[i + 1][k] %= mod;
            }
    int t;
    cin >> t;
    while(t --){
        cin >> n;
        //for(int i = 0; i < 10; i ++)
        //    dfs(i, 1);
        //cout << s << endl;
        int s = 0;
        for(int i = 0; i < 10; i ++)
            s = (s + dp[n][i]) % mod;
        cout << s << endl;
    }
    
    return 0;
} 