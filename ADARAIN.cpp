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

const int me = 1000025;

int N, M, L;
int x, y;
int s[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fastInput(N);
    fastInput(M);
    fastInput(L);
    
    for(int i = 0; i < N; i ++){
        fastInput(x);
        fastInput(y);
        s[x] ++;
        s[y + 1] --;
    }
    for(int i = 1; i <= L; i ++)
        s[i] += s[i - 1];
    while(M --){
        fastInput(x);
        printf("%d\n", s[x]);
    }
    
    return 0;
}
