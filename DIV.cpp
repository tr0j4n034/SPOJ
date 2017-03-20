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

const int me = 1000025;

int N;
int ps;
int primes[me], lp[me], d[me];
int good[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++){
        if(!lp[i]){
            primes[++ps] = i;
            lp[i] = i;
        }
        for(int j = 1; j <= ps && primes[j] <= lp[i] && i * primes[j] < me; j ++)
            lp[i * primes[j]] = primes[j];
    }
    d[1] = 1;
    for(int i = 2; i < me; i ++){
        int j = i;
        int cnt = 0;
        while(j % lp[i] == 0){
            j /= lp[i];
            cnt ++;
        }
        d[i] = d[j] * (cnt + 1);
    }
    for(int i = 1; primes[i] * primes[i] * primes[i] < me; i ++)
        d[primes[i] * primes[i] * primes[i]] = -1;
    for(int i = 1; i < 10; i ++)
        for(int j = i + 1; j < 10; j ++)
            good[primes[i] * primes[j]] = 1;
    int now = 0;
    for(int i = 1; i <= 1000000; i ++){
        if(good[d[i]]){
            now ++;
            if(now == 9)
                cout << i << endl, now = 0;
        }
    }
    
    return 0;
}