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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 10000025;
const int mod = 1000000007;

int T, N;
int d[me];


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    d[2] = 1;
    for(int i = 3; i < me; i ++)
        d[i] = 1LL * (i - 1) * (d[i - 1] + d[i - 2]) % mod;
    
    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        printf("%d\n", d[N]);
    }
    
    return 0;
}
