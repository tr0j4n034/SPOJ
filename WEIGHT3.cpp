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

int T, N, S;
int w[me];
bool can[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    
    while(T --){
        scanf("%d%d", &N, &S);
        for(int i = 1; i <= N; i ++)
            scanf("%d", &w[i]);
        
        fill(can, can + me, 0);
        can[0] = 1;
        
        int best = me;
        
        for(int i = 1; i <= N; i ++){
            for(int j = best - 1; j >= w[i]; j --){
                can[j] |= can[j - w[i]];
                if(can[j] && j >= S && j < best)
                    best = j;
            }
        }
        printf("%d\n", best - S);
    }

    return 0;
}
