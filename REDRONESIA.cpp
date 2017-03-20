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

const int me = 525;
const int mod = 1000000007;

int T, N, M;
int dp[me][me];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < me; i ++)
        dp[0][i] = 1;
    for(int i = 1; i < me; i ++)
        for(int j = 1; j < me; j ++){
            dp[i][j] = dp[i][j - 1];
            add(dp[i][j], dp[i - 1][j - 1]);
            if(i > 1)
                add(dp[i][j], dp[i - 2][j - 1]);
        }
    cin >> T;
    while(T --){
        cin >> N >> M;
        cout << dp[N][M] << endl;
    }
    
    return 0;
}
