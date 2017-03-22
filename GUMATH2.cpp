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

const int me = 30000025;
const int mod = 10000009;

int get(int N){
    int fac[10];
    fac[0] = 1;
    for(int i = 1; i < 10; i ++)
        fac[i] = fac[i - 1] * i;
    int now = 0;
    for(int i = 0; i < N; i ++){
        if(i & 1)
            now -= fac[N] / fac[i];
        else now += fac[N] / fac[i];
    }
    return now;
}
int brute(int N){
    vector<int> v;
    for(int i = 1; i <= N; i ++)
        v.push_back(i);
    int result = 0;
    do{
        int same = 0;
        for(int i = 0; i < N; i ++)
            if(i + 1 == v[i])
                same ++;
        if(same == 1)
            result ++;
    }while(next_permutation(v.begin(), v.begin() + N));
    return result;
}

int f[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    // formula found here:
    // http://oeis.org/search?q=1+0+3+8+45+264+1855&language=english&go=Search
    
    f[1] = 1;
    for(int i = 2; i < me; i ++){
        f[i] = 1LL * i * f[i - 1] % mod;
        if(i & 1)
            f[i] = (f[i] + mod + i) % mod;
        else f[i] = (f[i] + 3 * mod - i) % mod;
        assert(f[i] >= 0);
        //if(f[i] == 0)
        //  cout << "i = " << i << endl;
    }
    //for(int i = 1; i < 10; i ++)
    //    cout << f[i] << ", ";cout << endl;
    //for(int i = 0; i < 10; i ++){
    //    cout << f[i] << " vs " << f[mod + mod + i] << endl;
    //}cout << endl;
    
    // 1 0 3 8 45 264 1855
    
    int T;
    long long N;
    
    cin >> T;
    while(T --){
        cin >> N;
        N %= (mod << 1);
        cout << f[N] << endl;
    }
    
    return 0;
}

