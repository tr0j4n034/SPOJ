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

const int me = 10025;

int N;
long long x;
int cnt[63];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("C-large.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%lld", &x);
        for(int j = 0; j < 63; j ++)
            if(x & (1LL << j))
                cnt[j] ++;
    }
    long long result = 0;
    for(int j = 0; j < 63; j ++)
        if(cnt[j] != 0 && cnt[j] != N)
            result |= (1LL << j);
    cout << result << endl;
    
    return 0;
}
