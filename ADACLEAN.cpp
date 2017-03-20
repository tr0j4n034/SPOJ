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

const int muls[] = {23, 43};
const int mods[] = {715225741, 1000000007};

int T, N, K;
char ch[me];
int pw[2][me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    pw[0][0] = pw[1][0] = 1;
    for(int i = 0; i < 2; i ++)
        for(int j = 1; j < me; j ++)
            pw[i][j] = 1LL * pw[i][j - 1] * muls[i] % mods[i];
    
    fastInput(T);
    
    while(T --){
        set<pair<int, int>> s;
        
        fastInput(N);
        fastInput(K);
    
        pair<int, int> h(0, 0);
        
        for(int i = 1; i <= N; i ++){
            ch[i] = getchar_unlocked();
            
            if(i > K){
                h.first = 1LL * (h.first - 1LL * pw[0][K - 1] * ch[i - K] % mods[0] + mods[0]) % mods[0];
                h.second = 1LL * (h.second - 1LL * pw[1][K - 1] * ch[i - K] % mods[1] + mods[1]) % mods[1];
            }
            h.first = (1LL * h.first * muls[0] % mods[0] + ch[i]) % mods[0];
            h.second = (1LL * h.second * muls[1] % mods[1] + ch[i]) % mods[1];
            
            if(i >= K)
                s.insert(h);
        }
        printf("%d\n", (int)s.size());
    }
    
    return 0;
}
