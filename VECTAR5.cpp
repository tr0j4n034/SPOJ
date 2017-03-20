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
    puts("");
}

const int me = 1000025;
const int mod = 1000000007;

int T, N;
int pw[5][me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < 5; i ++)
        for(int j = 0; j < me; j ++){
            if(j == 0)
                pw[i][j] = 1;
            else pw[i][j] = 1LL * pw[i][j - 1] * i % mod;
        }
    fastInput(T);
    while(T --){
        fastInput(N);
        int ans = pw[4][N] - (2 * pw[3][N] % mod) + pw[2][N];
        if(ans < 0)
            ans += mod;
        if(ans >= mod)
            ans -= mod;
        fastPrint(ans);
    }
    
    // referred: http://oeis.org/search?q=2%2C+18%2C+110%2C+570&language=english&go=Search
    // :D
    
    return 0;
}
