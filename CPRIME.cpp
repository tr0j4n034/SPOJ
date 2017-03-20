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

const int me = 100000025;

int N;
int ps;
int primes[me], lp[me], s[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++){
        s[i] = s[i - 1];
        if(!lp[i]){
            primes[++ps] = i;
            lp[i] = i;
            s[i] ++;
        }
        for(int j = 1; j <= ps && primes[j] <= lp[i] && i * primes[j] < me; j ++)
            lp[i * primes[j]] = primes[j];
    }
    while(cin >> N){
        if(N == 0)
            break;
        double answer = fabs(1. - (double)N /log((double)N)/(double)s[N]) * 100.;
        cout.precision(1);
        cout << fixed << answer << endl;
    }
    
    return 0;
}