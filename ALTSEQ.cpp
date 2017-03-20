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

const int me = 5025;

int N;
int a[me], sign[me], dp[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i ++)
        cin >> a[i];
    for(int i = 1; i <= N; i ++){
        if(a[i] < 0)
            sign[i] = 1;
    }
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j < i; j ++)
            if(sign[i] != sign[j] && abs(a[i]) > abs(a[j]))
                dp[i] = max(dp[i], dp[j] + 1);
        if(dp[i] == 0)
            dp[i] = 1;
    }
    cout << *max_element(dp, dp + N + 1) << endl;
    
    return 0;
}
