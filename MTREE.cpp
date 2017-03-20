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
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;
const int mod = 1000000007;

int n;
int dp[me][2], sz[me];
vector<pair<int, int>> v[me];

int bin_pow(int a, int b){
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * bin_pow(a, b - 1) * a % mod;
    int half = bin_pow(a, b >> 1);
    return 1LL * half * half % mod;
}
void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

const int inverse = bin_pow(2, mod - 2);

void dfs1(int node, int par){
    sz[node] = 1;
    for(auto i : v[node]){
        if(i.first == par)
            continue;
        dfs1(i.first, node);
        sz[node] += sz[i.first];
    }
}
void dfs2(int node, int par){
    if(sz[node] == 1){
        dp[node][0] = 0;
        dp[node][1] = 0;
    }
    for(auto i : v[node]){
        if(i.first == par)
            continue;
        dfs2(i.first, node);
    }
    int sum = 0, square_sum = 0;
    for(auto i : v[node]){
        if(i.first == par)
            continue;
        int child_value = i.second;
        add(child_value, 1LL * dp[i.first][0] * i.second % mod);
        add(sum, child_value);
        add(square_sum, 1LL * child_value * child_value % mod);
        add(dp[node][0], child_value);
        add(dp[node][1], dp[i.first][0]);
        add(dp[node][1], dp[i.first][1]);
    }
    //cout << node << ", sum = " << sum << ", square_sum = " << square_sum << endl;
    sum = 1LL * sum * sum % mod;
    add(sum, mod - square_sum);
    sum = 1LL * sum * inverse % mod;
    add(dp[node][1], sum);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i < n; i ++){
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        v[a].push_back(make_pair(b, l));
        v[b].push_back(make_pair(a, l));
    }
    dfs1(1, -1);
    dfs2(1, -1);
    //for(int i = 1; i <= n; i ++)
      //  cout << i << " " << sz[i] << endl;
    //for(int i = 1; i <= n; i ++)
      //  cout << i << " ---> " << dp[i][0] << " and " << dp[i][1] << endl;
    int ans = dp[1][0];
    add(ans, dp[1][1]);
    printf("%d\n", ans);
    
    return 0;
}