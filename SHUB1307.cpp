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

const int me = 125;
const int sz = 505;

int T, N, M, K;
int a[me][me], can[me][me][sz];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    can[0][0][0] = 1;
    
    scanf("%d", &T);
    
    while(T --){
        scanf("%d%d%d", &N, &M, &K);
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= M; j ++)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= M; j ++)
                for(int k = 1; k <= K; k ++)
                    can[i][j][k] = 0;
        
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= M; j ++)
                for(int k = a[i][j]; k <= K; k ++)
                    can[i][j][k] = (can[i - 1][j - 1][k - a[i][j]]
                                    || can[i - 1][j][k - a[i][j]] || can[i][j - 1][k - a[i][j]]);
        int ans = -1;
        for(int i = K; i > 0; i --)
            if(can[N][M][i] == 1){
                ans = i;
                break;
            }
        printf("%d\n", ans);
    }
    
    return 0;
}
