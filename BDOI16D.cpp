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

template <class T> void fastInput(T &n){
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
    n *= sign;
}
template<class T> void fastPrint(T n){
    if(n == 0){
        puts("0");
        return;
    }
    char buffer[256];
    int ptr = 0, sign = 1;
    
    if(n < 0){
        sign = -1;
        n *= -1;
    }
    while(n > 0){
        buffer[ptr ++] = (char)(n % 10 + '0');
        n /= 10;
    }
    if(sign == -1)
        putchar_unlocked('-');
    for(int i = ptr - 1; i >= 0; i --)
        putchar_unlocked(buffer[i]);
    putchar_unlocked('\n');
}

const int me = 100025;
const int sz = 51;

int T, N, M, R;
int l[me], sum[me], dp[me][sz];
pair<int, int> a[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fastInput(T);
    
    for(int cases = 0; cases < T; cases ++){
        fastInput(N);
        fastInput(R);
        fastInput(M);
        R <<= 1;
        
        for(int i = 1; i <= N; i ++){
            fastInput(a[i].first);
            fastInput(a[i].second);
        }
        sort(a + 1, a + N + 1);
        
        int ptr = 0;
        for(int i = 1; i <= N; i ++){
            while(a[ptr].first + R < a[i].first)
                ++ptr;
            l[i] = ptr;
            sum[i] = sum[i - 1] + a[i].second;
        }
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= M; j ++)
                dp[i][j] = 0;
        for(int j = 1; j <= M; j ++)
            for(int i = 1; i <= N; i ++){
                dp[i][j] = max(dp[i - 1][j], dp[l[i] - 1][j - 1] + sum[i] - sum[l[i] - 1]);
            }
        printf("Case %d: %d\n", cases + 1, dp[N][M]);
    }
    
    return 0;
}
