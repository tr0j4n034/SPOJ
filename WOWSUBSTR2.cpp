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

const int me = 1000025;
const int mod = 100007;

int T, N, M;
int cnt[me];
char ch;
int s[me];

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

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    FastInput(T);
    
    for(int c = 0; c < T; c ++){
        FastInput(N);
        FastInput(M);
        
        fill(cnt, cnt + M + 1, 0);
        for(int i = 1; i <= N; i ++)
            FastInput(s[i]);
        int ptr = 1, ans = 0;
        for(int i = 1; i <= N; i ++){
            while(ptr <= N){
                cnt[s[ptr]] ++;
                if(cnt[s[ptr]] == 2){
                    break;
                }
                ptr ++;
            }
            cnt[s[ptr]] --;
            cnt[s[i]] --;
            int l = ptr - i;
            ans = (ans + l * (l + 1) / 2) % mod;
        }
        printf("Case %d: %d\n", c + 1, ans);
    }
    
    return 0;
}
