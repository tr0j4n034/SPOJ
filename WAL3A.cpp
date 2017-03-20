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

int T, N;
long long s;
int x[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        for(int i = 1; i <= N; i ++)
            scanf("%d", &x[i]);
        x[N + 1] = 0;
        s = 0;
        for(int i = 1; i <= N; i ++){
            s += min(x[i], max(x[i - 1], x[i + 1]));
        }
        printf("%lld\n", s);
    }
    
    return 0;
}
