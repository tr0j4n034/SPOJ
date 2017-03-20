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

int T, N, Q;
int x;
int cnt[50];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    // Testing fast i/o
    
    FastInput(T);
    
    while(T --){
        FastInput(N);
        for(int i = 0; i < 31; i ++)
            cnt[i] = 0;
        for(int i = 0; i < N; i ++){
            FastInput(x);
            for(int j = 0; j < 31; j ++)
                if(x & (1 << j))
                    cnt[j] ++;
        }
        unsigned long long sum = 0;
        for(int i = 0; i < 31; i ++)
            sum += (1LL << i) * (1LL * cnt[i] * (cnt[i] - 1) / 2 + 1LL * cnt[i] * (N - cnt[i]));
        
        unsigned long long d = 1LL * N * (N - 1) / 2;
        unsigned long long gcd = __gcd(sum, d);
        sum /= gcd, d /= gcd;

        printf("%llu/%llu\n", sum, d);
    }
    
    return 0;
}
