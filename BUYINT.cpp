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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 40025;

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

/*
 even x
 odd y = n - x
 E = x * (x - 1) / 2 + y * (y - 1) / 2
 O = x * y
 D = abs(E - O) = (x*x - 2*x*y+y*y - x - y) / 2 = ((x - y)^2-x-y)/2=
 = ((2*x - n)^2-n)/2 = (4*x*x-4*x*n+n*n-n)/2=()
 */


int T, N;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fastInput(T);
    for(int cases = 0; cases < T; cases ++){
        fastInput(N);
        int x = ((int)sqrt(1. * N) + N) / 2;
        int D = N;
        for(int i = -1; i < 2; i ++){
            int xx = x + i;
            D = min(D, abs(((2 * xx - N) * (2 * xx - N) - N) / 2));
        }
        printf("Case %d: %d\n", cases + 1, D);
    }
    
    return 0;
}
