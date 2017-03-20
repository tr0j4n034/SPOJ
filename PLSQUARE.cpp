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

const int me = 225;
const int mods[] = {715225741, 1000000007};
const int muls[] = {43, 31};

int n;
char row[me][me][me], col[me][me][me], pal[me][me][me];
int rowh[2][me][me][me], colh[2][me][me][me];
string s[me];

/*
 4
 babb
 acaz
 babx
 fdhk
 */
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        s[i] = "$" + s[i];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++)
            row[i][j][j] = 1;
        for(int j = 1; j < n; j ++)
            row[i][j][j + 1] = s[i][j] == s[i][j + 1];
        for(int d = 2; d < n; d ++)
            for(int j = 1; j + d <= n; j ++){
                row[i][j][j + d] = row[i][j + 1][j + d - 1] && s[i][j] == s[i][j + d];
            }
        for(int j = 1; j <= n; j ++)
            col[i][j][j] = 1;
        for(int j = 1; j < n; j ++)
            col[i][j][j + 1] = s[j][i] == s[j + 1][i];
        for(int d = 2; d < n; d ++)
            for(int j = 1; j < n; j ++)
                col[i][j][j + d] = col[i][j + 1][j + d - 1] && s[j][i] == s[j + d][i];
    }
    for(int p = 0; p < 2; p ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++)
                rowh[p][i][j][j] = s[i][j];
            for(int d = 1; d < n; d ++)
                for(int j = 1; j + d <= n; j ++)
                    rowh[p][i][j][j + d] = (1LL * muls[p] * rowh[p][i][j][j + d] % mods[p] + s[i][j + d]) % mods[p];
            for(int j = 1; j <= n; j ++)
                colh[p][i][j][j] = s[j][i];
            for(int d = 1; d < n; d ++)
                for(int j = 1; j + d <= n; j ++)
                    colh[p][i][j][j + d] = (1LL * muls[p] * colh[p][i][j][j + d - 1] % mods[p] + s[j + d][i]) % mods[p];
        }
    }
    int ans = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            pal[i][j][1] = 1;
    for(int i = 1; i < n; i ++)
        for(int j = 1; j < n; j ++){
            pal[i][j][2] = s[i][j] == s[i][j + 1] && s[i][j] == s[i + 1][j] && s[i][j] == s[i + 1][j + 1];
            if(pal[i][j][2])
                ans = 2;
        }
    for(int r = 3; r <= n; r ++)
        for(int i = 1; i + r - 1 <= n; i ++)
            for(int j = 1; j + r - 1 <= n; j ++){
                pal[i][j][r] = pal[i + 1][j + 1][r - 2]
                && row[i][j][j + r - 1] && row[i + r - 1][j][j + r - 1]
                && col[j][i][i + r - 1] && col[j + r - 1][i][i + r - 1]
                && rowh[0][i][j][j + r - 1] == rowh[0][i + r - 1][j][j + r - 1]
                && rowh[1][i][j][j + r - 1] == rowh[1][i + r - 1][j][j + r - 1]
                && colh[0][j][i][i + r - 1] == colh[0][j + r - 1][i][i + r - 1]
                && colh[1][j][i][i + r - 1] == colh[1][j + r - 1][i][i + r - 1];
                if(pal[i][j][r])
                    ans = max(ans, r);
            }
    cout << ans << endl;
    
    return 0;
}
