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

int T, N;
int x;
int used[me], p[me], lp[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!lp[i]){
            for(int j = i; j < me; j += i)
                lp[j] = i;
        }
    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        fill(used, used + me, 0);
        for(int i = 0; i < N; i ++){
            scanf("%d", &x);
            while(x > 1){
                int d = lp[x];
                used[d] = 1;
                while(x % d == 0)
                    x /= d;
            }
        }
        for(int i = 2; i < me; i ++)
            if(lp[i] == i && !used[i]){
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}
