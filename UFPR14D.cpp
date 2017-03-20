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

const int me = 100025;

int N, l, r;
int a[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fastInput(N);
    for(int i = 1; i <= N; i ++){
        fastInput(a[i]);
        a[i] += a[i - 1];
    }
    fastInput(N);
    while(N --){
        fastInput(l);
        fastInput(r);
        printf("%d\n", a[r] - a[l - 1]);
    }
    
    return 0;
}
