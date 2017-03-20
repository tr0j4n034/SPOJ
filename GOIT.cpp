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

const int me = 1025;

int t, n, k;
double p[6], prob[me][me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    
    while(t --){
        scanf("%d%d", &n, &k);
        
        prob[0][0] = 1.;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < 6; j ++)
                scanf("%lf", &p[j]);
            for(int j = 0; j <= i; j ++){
                prob[i][j] = prob[i - 1][j] * (1. - p[5]);
                if(j > 0)
                    prob[i][j] += prob[i - 1][j - 1] * p[5];
            }
        }
        double ans = 0.;
        for(int i = k; i <= n; i ++)
            ans += prob[n][i];
        printf("%.6lf\n", ans);
    }
    
    return 0;
}
