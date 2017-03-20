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

int N, M;
int a[me][me], hor[2][me][me], sum[2][me][me];

int get(int w, int l1, int r1, int l2, int r2){
    return sum[w][l2][r2] - sum[w][l2][r1 - 1] - sum[w][l1 - 1][r2] + sum[w][l1 - 1][r1 - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N >> M;
    
    for(int i = 0; i < M; i ++){
        int u, v;
        cin >> u >> v;
        a[u][v] ++;
    }
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= N; j ++){
            hor[0][i][j] = hor[0][i][j - 1] + a[i][j];
            hor[1][i][j] = hor[1][i][j - 1] + (a[i][j] > 0);
        }
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= N; j ++){
            sum[0][i][j] = sum[0][i - 1][j] + hor[0][i][j];
            sum[1][i][j] = sum[1][i - 1][j] + hor[1][i][j];
        }
    
    int best = 0;
    for(int i = 1; i <= M; i ++){
        if(M % i)
            continue;
        int j = M / i;
        for(int k = 1; k + i - 1 <= N; k ++)
            for(int q = 1; q + j - 1 <= N; q ++){
                best = max(best, get(1, k, q, k + i - 1, q + j - 1));
            }
    }
    cout << M - best << endl;
    
    return 0;
}
