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

const int me = 1000025;

int t, n, m;
int dp[me];

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 1; i < me; i ++)
        for(int j = i; j < me; j += i)
            dp[j] ++;
    scanf("%d", &t);
    while(t --){
        scanf("%d%d", &n, &m);
        printf("%d\n", dp[__gcd(n, m)]);
    }
    
    return 0;
}