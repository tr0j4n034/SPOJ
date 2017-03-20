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

const int me = 10000025;

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

int N, x;
int f[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i < me; i += 2)
        f[i] = i;
    for(int i = 2; i < me; i += 2){
        int s = 0;
        for(int j = 0; (1 << j) <= i; j ++){
            s = s << 1;
            if(i & (1 << j))
                s ++;
        }
        f[i] = s;
    }
    
    fastInput(N);
    while(N --){
        fastInput(x);
        printf("%d\n", f[x]);
    }
    
    return 0;
}
