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
const int mod = 1000000007;

int T, N, M;

int power(int a, int b){
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * power(a, b - 1) * a % mod;
    int half = power(a, b >> 1);
    return 1LL * half * half % mod;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N >> M;
        int x = 1LL * ((power(N, M) - 1 + mod) % mod) * power(N - 1, mod - 2) % mod;
        int y = power(N, M);
        cout << x << " " << y << endl;
    }
    
    return 0;
}
