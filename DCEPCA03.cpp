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

const int me = 10025;

int phi[me], d[me];
long long sum[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!d[i])
            for(int j = i; j < me; j += i)
                if(!d[j])
                    d[j] = i;
    phi[1] = 1;
    for(int i = 2; i < me; i ++){
        int j = i;
        while(j % d[i] == 0)
            j /= d[i];
        phi[i] = phi[j] * (i / j) * (d[i] - 1) / (d[i]);
    }
    for(int i = 1; i < me; i ++){
        sum[i] = sum[i - 1] + phi[i];
    }
    
    int t, n;
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        long long ans = 1LL * sum[n] * sum[n];
        cout << ans << endl;
    }
    
    return 0;
}

