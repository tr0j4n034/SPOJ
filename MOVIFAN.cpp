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

const int me = 300025;

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

const int mod = 1000000007;

int T, N, L;
int st[me], dp[me], sum[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    // Testing fast i/o
    
    FastInput(T);
    while(T --){
        FastInput(N);
        FastInput(L);
        for(int i = 1; i <= N; i ++)
            FastInput(st[i]);
        sort(st + 1, st + N + 1);
        
        int ans = 0, ptr = 1;
        //dp[0] = 1;
        for(int i = 1; i <= N; i ++){
            while(ptr <= i && st[ptr] + L <= st[i])
                ++ptr;
            dp[i] = sum[ptr - 1] + 1;
            sum[i] = sum[i - 1] + dp[i];
            ans = (ans + dp[i]) % mod;
        }
        FastPrint(ans);
    }
    
    return 0;
}
