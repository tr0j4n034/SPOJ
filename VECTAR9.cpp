#include<iostream>
#include <list>
#include <stack>
#include <vector>
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
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;
const int sz = 13;

int t;
long long k;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int fx[1 << sz];
long long mul[1 << sz];

long long get(long long m){
    long long s = 0;
    for(int i = 0; i < (1 << sz); i ++){
        if(fx[i])
            s -= m / mul[i];
        else s += m / mul[i];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    mul[0] = 1;
    for(int i = 1; i < (1 << sz); i ++){
        for(int j = 0; j < sz; j ++)
            if(i & (1 << j)){
                mul[i] = mul[i ^ (1 << j)] * primes[j];
                fx[i] = fx[i ^ (1 << j)] ^ 1;
                break;
            }
    }
    cin >> t;
    while(t --){
        cin >> k;
        long long low = 1, high = 304250263527210LL, mid, best = high;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            long long total = mid - get(mid);
            if(total >= k){
                best = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << best << endl;
    }

    return 0;
}

