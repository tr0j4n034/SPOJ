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

const int me = 100025;

template <class T> void FastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    if(sign == -1)
        n = ~n + 1;
}
template<class T> void FastPrint(T n){
    if(n == 0){
        puts("0");
        return;
    }
    char buffer[256];
    int ptr = 0, sign = 1;
    
    if(n < 0){
        sign = -1;
        n = ~n + 1;
    }
    while(n > 0){
        buffer[ptr ++] = (char)(n % 10 + '0');
        n /= 10;
    }
    if(sign == -1)
        putchar_unlocked('-');
    for(int i = ptr - 1; i >= 0; i --)
        putchar_unlocked(buffer[i]);
    puts("");
}

int T, N, K;
int dp[me][2];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    // Testing fast i/o
    
    FastInput(T);
    
    while(T --){
        FastInput(N);
        FastInput(K);
        
        dp[1][0] = 1;
        dp[1][1] = 1;
        
        for(int i = 2; i <= N; i ++){
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 5000011;
            dp[i][1] = i > K + 1 ? (dp[i - K - 1][0] + dp[i - K - 1][1]) % 5000011 : 1;
        }
        FastPrint((dp[N][0] + dp[N][1]) % 5000011);
    }
    
    return 0;
}
