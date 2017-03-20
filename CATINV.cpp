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
int x, y;
int has[me], l[me];
pair<int, int> st[me];
 
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    // Testing fast i/o
    
    FastInput(T);
    
    for(int c = 0; c < T; c ++){
        FastInput(N);
        FastInput(Q);
        
        fill(has, has + me, 0);
        fill(l, l + me, 0);
        fill(st, st + me, make_pair(0, 0));
        
        for(int i = 0; i < N; i ++){
            FastInput(x);
            FastInput(y);
            has[x] ++;
            has[y] --;
        }
        for(int i = 1; i < me; i ++)
            has[i] += has[i - 1];
        for(int i = 1; i < me; ){
            if(!has[i]){
                i ++;
                continue;
            }
            int j = i;
            while(j < me && has[j] == has[i])
                j ++;
            if(l[has[i]] < j - i){
                l[has[i]] = j - i;
                st[has[i]] = make_pair(i, j - 1);
            }
            i = j;
        }
        printf("Case %d:\n", c + 1);
        while(Q --){
            FastInput(x);
            if(l[x] == 0)
                puts("-1");
            else printf("%d %d\n", st[x].first, st[x].second);
        }
    }
    
    return 0;
}