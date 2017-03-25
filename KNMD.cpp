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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
 
using namespace std;
 
const int me = 1000025;
 
int N, K;
int a[me];
long long dp[1 << 8];
 
int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i ++)
        scanf("%d", &a[i]);
    sort(a, a + N);
    long long sum = accumulate(a, a + N, 0LL);
    N = min(N, 250);
    
    fill(dp, dp + K, -1);
    dp[0] = 0;
    for(int i = 0; i < N; i ++){
        long long tdp[1 << 8];
        for(int j = 0; j < K; j ++)
            tdp[j] = dp[j];
        for(int j = 0; j < K; j ++)
            if(tdp[j] != -1 && (tdp[(j + a[i]) % K] == -1 || tdp[(j + a[i]) % K] > tdp[j] + a[i]))
                dp[(j + a[i]) % K] = tdp[j] + a[i];
        if(tdp[a[i] % K] == -1 || tdp[a[i] % K] > a[i])
            dp[a[i] % K] = a[i];
    }//cout << sum << endl;
    for(int i = 0; i < K; i ++){
        if(dp[(sum + K - i) % K] == -1)
            printf("-1");
        else{
            long long result = sum - dp[(sum + K - i) % K];
            if(result < 1)
                result = -1;
            printf("%lld", result);
        }
        if(i < K - 1)
            putchar(' ');
    }
    putchar('\n');
    
    return 0;
}