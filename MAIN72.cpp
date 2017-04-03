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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bitset>

using namespace std;

const int me = 100025;

int T, N;
int a[me], dp[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> N;
        for(int i = 0; i < N; i ++)
            cin >> a[i];
        fill(dp, dp + me, 0);
        dp[0] = 1;
        for(int i = 0; i < N; i ++)
            for(int j = me - 1; j >= a[i]; j --)
                dp[j] |= dp[j - a[i]];
        int s = 0;
        for(int i = 0; i < me; i ++)
            if(dp[i])
                s += i;
        cout << s << endl;
    }
    
    return 0;
}
