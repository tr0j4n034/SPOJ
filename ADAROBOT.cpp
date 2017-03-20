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

const int me = 200000025;

int Q, N;
int cubes[100];
long long t[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 1; i < 100; i ++)
        cubes[i] = i * i * i;
    for(int i = 2; i < me; i ++)
        t[i] = t[i - 2] + cubes[__builtin_ffsl(1LL * i * (i - 1))];
    
    scanf("%d", &Q);
    while(Q --){
        scanf("%d", &N);
        printf("%lld\n", t[N]);
    }
    
    return 0;
}
