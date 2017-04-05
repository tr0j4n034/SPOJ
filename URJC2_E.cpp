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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bitset>

using namespace std;

const int me = 50025;
const int sz = 105;
const int mod = 1000000007;

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

int T, N, H, K, Q;
int a[sz][me], pref[sz][me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fastInput(T);
    while(T --){
        fastInput(N);
        fastInput(H);
        fastInput(K);
        for(int i = 1; i <= N; i ++){
            for(int j = 1; j <= K; j ++)
                fastInput(a[i][j]);
            for(int j = 1; j <= K; j ++)
                pref[i][j] = pref[i][j - 1] + a[i][j];
        }
        fastInput(Q);
        while(Q --){
            int l, r;
            fastInput(l);
            fastInput(r);
            int result = 0;
            for(int i = 1; i <= N; i ++)
                if(pref[i][r] - pref[i][l - 1] > H)
                    result ++;
            printf("%d - %d\n", result, N - result);
        }
    }
    
    return 0;
}
