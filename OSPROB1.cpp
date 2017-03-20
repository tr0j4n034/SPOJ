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
//#include <unordered_map>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 125;

int T, N;
int a[me], sum[me], dp[me][me];
int solve(int l, int r){
    if(l >= r)
        return 0;
    int &s = dp[l][r];
    if(s != -1)
        return s;
    s = 0;
    for(int i = l; i <= r; i ++){
        int taken = sum[i] - sum[l - 1];
        int mine = 0, pos = i;
        for( ; pos < N && mine + a[pos + 1] < taken; )
            pos ++, mine += a[pos], s = max(s, mine + solve(pos + 1, r));
    }
    return s;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        for(int i = 1; i <= N; i ++)
            cin >> a[i];
        for(int i = 1; i <= N; i ++)
            sum[i] = sum[i - 1] + a[i];
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= N; j ++)
                dp[i][j] = -1;
        int mine = solve(1, N);
        cout << sum[N] - mine << " " << mine << endl;
    }
    
    return 0;
}
