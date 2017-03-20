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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 125;
const int mod = 1000000007;

int bin_pow(int a, int b){
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * bin_pow(a, b - 1) * a % mod;
    int half = bin_pow(a, b >> 1);
    return 1LL * half * half % mod;
}

int T, A, B;
int dp[me][me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0][0] = 1;
    
    for(int i = 0; i < me; i ++)
        for(int j = 0; j < me; j ++){
            if(i == 0 && j == 0)
                continue;
            dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
            dp[i][j] %= mod;
        }
    
    cin >> T;
    
    while(T --){
        cin >> A >> B;
        if(A < B)
            swap(A, B);
        
        if(A < 25 || A - B < 2 || (A > 25 && A - B > 2))
            cout << 0 << endl;
        else if(A == 25)
            cout << dp[24][B] << endl;
        else cout << 1LL * dp[24][24] * bin_pow(2, A - 26) % mod << endl;
    }
    
    
    return 0;
}
