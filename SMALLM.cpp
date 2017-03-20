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

const int me = 100000025;

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}

int lp[me], primes[me], mul[me];
int ps;

int T, M;
int ans[123456];
pair<int, int> data[123456];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < me; i ++){
        if(!lp[i]){
            primes[++ps] = i;
            lp[i] = i;
        }
        for(int j = 1; j <= ps && primes[j] <= lp[i] && i * primes[j] < me; j ++)
            lp[i * primes[j]] = primes[j];
    }
    
    T = uget();
    M = uget();
    for(int i = 0; i < T; i ++){
        data[i].first = uget();
        data[i].second = i;
    }
    sort(data, data + T);
    
    int ptr = 0, result = 1;
    for(int i = 2; i < me; i ++){
        while(data[ptr].first == i - 1){
            ans[data[ptr].second] = result;
            ptr ++;
        }
        if(ptr == T)
            break;
        if(mul[lp[i]] == 0)
            mul[lp[i]] = 1;
        if(i % mul[lp[i]] == 0){
            int go = i / mul[lp[i]];
            if(go % lp[i] == 0){
                mul[lp[i]] = 1LL * mul[lp[i]] * lp[i] % M;
                result = 1LL * result * lp[i] % M;
            }
        }
    }
    for(int i = 0; i < T; i ++)
        printf("%d\n", ans[i]);
    
    return 0;
}
