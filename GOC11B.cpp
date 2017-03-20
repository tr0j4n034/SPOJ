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

const int me = 100025;
const int mod = 1000000007;

int bin_pow(int a, int b){
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * bin_pow(a, b - 1) * a % mod;
    int half = bin_pow(a, b >> 1);
    return 1LL * half * half % mod;
}

int T, N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    for(int c = 0; c < T; c ++){
        cin >> N >> M;
        int ans = bin_pow(M, N) - bin_pow(M, (N + 1) / 2);
        if(ans < 0)
            ans += mod;
        cout << "Case " << c + 1 << ": " << ans << endl;
    }
    
    return 0;
}
