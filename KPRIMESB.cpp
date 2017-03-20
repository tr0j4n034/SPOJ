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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 1000025;

int T, N, K;
int primes[10], p[me], sum[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    sum[1] = 1;
    for(int i = 2; i < me; i ++)
        if(!p[i])
            for(int j = i + i; j < me; j += i)
                p[j] = 1;
    for(int i = 2; i < me; i ++)
        sum[i] = sum[i - 1] + 1 - p[i];
    
    cin >> T;
    for(int cases = 0; cases < T; cases ++){
        cin >> N >> K;
        for(int i = 0; i < K; i ++)
            cin >> primes[i];
        int active = 0;
        for(int mask = 0; mask < (1 << K); mask ++){
            int product = 1;
            for(int i = 0; i < K && product <= N; i ++)
                if(mask & (1 << i))
                    product *= primes[i];
            if(__builtin_popcount(mask) & 1)
                active -= N / product;
            else active += N / product;
        }
        for(int i = 0; i < K; i ++)
            if(primes[i] <= N)
                active ++;
        active -= sum[N];
        cout << "Case " << cases + 1 << ": " << active << endl;
    }
    
    return 0;
}
