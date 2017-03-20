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

const int me = 100025;

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

int N, Q, L, R;
int a[me], s[me];
bitset<me> b[2];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &N, &Q);
    b[0][0] = 1;
    for(int i = 1; i <= N; i ++){
        scanf("%d", &a[i]);
        b[i & 1] = b[!(i & 1)] | (b[!(i & 1)] << a[i]);
    }
    for(int i = 1; i < me; i ++)
        s[i] = s[i - 1] + (b[N & 1][i]);
    while(Q --){
        scanf("%d%d", &L, &R);
        printf("%d\n", s[R] - s[L - 1]);
    }
    
    return 0;
}
