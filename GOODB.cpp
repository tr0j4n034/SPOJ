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

const int me = 325;
const int mod = 1000000007;

int N, W, T, R;
int comb[me][me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 0; i < me; i ++)
        for(int j = 0; j <= i; j ++){
            if(i == j)
                comb[i][j] = 1;
            else comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }
    cin >> N >> W >> T >> R;
    int ans = comb[N][W];
    N -= W;
    ans = 1LL * ans * comb[N][T] % mod;
    cout << ans << endl;
    
    return 0;
}
