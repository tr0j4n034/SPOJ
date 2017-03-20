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
#include <unordered_map>
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

int T, K;
long long L, R;
int prime[me], lp[me], d[me];
vector<long long> v[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!prime[i]){
            lp[i] = i;
            for(int j = i + i; j < me; j += i){
                prime[j] = 1;
                if(!lp[j])
                    lp[j] = i;
            }
        }
    
    for(int i = 1; i < me; i ++){
        vector<int> coefficients;
        int j = i;
        
        while(j > 1){
            int now = 0;
            int D = lp[j];
            while(j % D == 0){
                j /= D;
                now ++;
            }
            coefficients.push_back(now);
        }
        int s = 1;
        for(int j : coefficients)
            s = s * (j + j + 1);
        v[s].push_back(1LL * i * i);
    }
    
    fastInput(T);
    
    while(T --){
        fastInput(K);
        fastInput(L);
        fastInput(R);
        
        int result = (int)(upper_bound(v[K].begin(), v[K].end(), R) - v[K].begin())
        - (int)(lower_bound(v[K].begin(), v[K].end(), L) - v[K].begin());
        printf("%d\n", result);
    }
    
    return 0;
}
