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

int T, N;
int pw[me], pr[me];

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 11; i ++)
        pw[i] = 1;
    for(int i = 10; i < me; i ++)
        pw[i] = pw[i / 10] * 10;
    pr[1] = 1;
    for(int i = 2; i < me; i ++)
        if(!pr[i]){
            for(int j = i + i; j < me; j += i)
                pr[j] = 1;
        }
    for(int i = 10; i < me; i ++)
        if(!pr[i] && (pr[i % pw[i]] || (i % pw[i] < pw[i / 10])))
            pr[i] = 1;
    for(int i = 1; i < me; i ++)
        pr[i] = !pr[i] + pr[i - 1];
    
    fastInput(T);
    while(T --){
        fastInput(N);
        printf("%d\n", pr[N]);
    }
    
    
    return 0;
}
