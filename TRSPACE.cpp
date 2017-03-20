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

int T, N, S;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    FastInput(T);
    for(int c = 0; c < T; c ++){
        FastInput(N);
        FastInput(S);
        
        long long ans = 0;
        
        while(N --){
            int x;
            FastInput(x);
            
            ans += x / S;
            if(x % S > 0)
                ans ++;
        }
        printf("Case %d: %lld\n", c + 1, ans * S);
    }

    return 0;
}
