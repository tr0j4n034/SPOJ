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

const int me = 2025;

int T, N;
char ch;
int border[4][me][me];
char a[me][me];

/*
    0 --> left
    1 --> right
    2 --> up
    3 --> down
*/

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d", &T);
    
    while(T --){
        scanf("%d", &N);
        getchar_unlocked();
        for(int i = 1; i <= N; i ++){
            int j = 0;
            while(ch = getchar(), ch != '\n')
                a[i][++j] = ch;
        }
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= N; j ++){
                border[0][i][j] = (a[i][j] == '#') ? border[0][i][j - 1] : j;
            }
        for(int i = 1; i <= N; i ++)
            for(int j = N; j > 0; j --){
                border[1][i][j] = (a[i][j] == '#') ? (j == N ? N + 1 : border[1][i][j + 1]) : j;
            }
        for(int j = 1; j <= N; j ++)
            for(int i = 1; i <= N; i ++){
                border[2][i][j] = (a[i][j] == '#') ? border[2][i - 1][j] : i;
            }
        for(int j = 1; j <= N; j ++)
            for(int i = N; i > 0; i --){
                border[3][i][j] = (a[i][j] == '#') ? (i == N ? N + 1 : border[3][i + 1][j]) : i;
            }
        int answer = 0;
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= N; j ++)
                if(a[i][j] == '#'){
                    int r = min(min(j - border[0][i][j], border[1][i][j] - j),
                                min(i - border[2][i][j], border[3][i][j] - i));
                    if(r > answer)
                        answer = r;
                }
        printf("%d\n", answer);
    }
    
    return 0;
}
