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
    n *= sign;
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
    //puts("");
}


int N;
int a[me], sum[me];
map<int, int> pref;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    FastInput(N);
    for(int i = 1; i <= N; i ++){
        FastInput(a[i]);
        sum[i] = sum[i - 1] + a[i];
        pref[sum[i]] = i;
    }
    for(int i = 1; i <= N; i ++){
        int now = 1;
        while(now != N + 1){
            if(!pref.count(sum[now - 1] + sum[i]))
                break;
            now = pref[sum[now - 1] + sum[i]] + 1;
        }
        if(now == N + 1){
            FastPrint(sum[i]);
            putchar_unlocked(' ');
            FastPrint(sum[N] / sum[i]);
            putchar_unlocked('\n');
        }
    }
    
    return 0;
}
