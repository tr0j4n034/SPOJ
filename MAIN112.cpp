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
#include <list>
#include <unordered_map>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 15;

int T, N;
int sz[1 << me], perm[me], cost[me], dp[1 << me][me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i < (1 << me); i ++)
        for(int j = 0; j < me; j ++)
            if(i & (1 << j)){
                sz[i] = sz[i ^ (1 << j)] + 1;
                break;
            }
    cin >> T;
    while(T --){
        cin >> N;
        for(int i = 0; i < N; i ++)
            cin >> perm[i];
        for(int i = 0; i < N; i ++)
            cin >> cost[i];
        for(int i = 1; i < (1 << N); i ++)
            for(int j = 0; j < N; j ++)
                dp[i][j] = 1234567;
        for(int i = 0; i < N; i ++)
            dp[1 << i][i] = 0;
        for(int i = 1; i < (1 << N); i ++){
            for(int j = 0; j < N; j ++)
                if(i & (1 << j)){
                    int other = i ^ (1 << j);
                    for(int k = 0; k < N; k ++)
                        if(other & (1 << k)){
                            dp[i][j] = min(dp[i][j], dp[other][k] + abs(perm[j] - perm[k]) * cost[sz[i] - 1]);
                        }
                }
        }
        int result = 1234567;
        for(int i = 0; i < N; i ++)
            result = min(result, dp[(1 << N) - 1][i]);
        cout << result << endl;
    }
    
    return 0;
}
