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

const int me = 5025;

int t;
long long n;

long long get(long long n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 2;
    if(n & 1)
        return get(n >> 1) << 1;
    return get(n >> 1);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%lld", &n);
        long long s = get(n);
        printf("%lld %lld\n", n - s + 1, s);
    }
    
    return 0;
}

