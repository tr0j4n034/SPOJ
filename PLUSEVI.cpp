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
#include <set>
#include <map>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 2025;

int n;
char ch;
int a[me][me], row[me][me], col[me][me], sum[me][me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    getchar();
    for(int i = 1; i <= n; i ++){
        int j = 1;
        while((ch = getchar()) != '\n'){
            a[i][j] = ch == '1';
            j ++;
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++){
            row[i][j] = row[i][j - 1] + a[i][j];
            col[i][j] = col[i - 1][j] + a[i][j];
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            sum[i][j] = sum[i][j - 1] + col[i][j];
    int ans = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++){
            if(a[i][j] == 0)
                continue;
            int li = i - 1, lj = j - 1, ri = i + 1, rj = j + 1;
            while(li > 0 && lj > 0 && ri <= n && rj <= n){
                if(row[i][rj] - row[i][lj - 1] != rj - lj + 1)
                    break;
                if(col[ri][j] - col[li - 1][j] != ri - li + 1)
                    break;
                if(sum[ri][rj] - sum[ri][lj - 1] - sum[li - 1][rj] + sum[li - 1][lj - 1] != rj - lj + ri - li + 1)
                    break;
                ans ++;
                li --;
                lj --;
                ri ++;
                rj ++;
            }
        }
    cout << ans << endl;
    
    return 0;
}
