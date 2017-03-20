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

const int me = 100025;

int T;
long long N, K;
int used[me];
vector<long long> primes;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!used[i]){
            primes.push_back(1LL * i * i);
            for(int j = i + i; j < me; j += i)
                used[j] = 1;
        }
    scanf("%d", &T);
    while(T --){
        scanf("%lld%lld", &N, &K);
        int total = (int)(upper_bound(primes.begin(), primes.end(), N) - primes.begin());
        int good = total - (int)(upper_bound(primes.begin(), primes.end(), K) - primes.begin());
        if(good < 0)
            good = 0;
        printf("%d %d\n", total, good);
    }
    
    return 0;
}
