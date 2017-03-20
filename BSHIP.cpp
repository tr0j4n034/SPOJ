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

int N, M, S;
char ch;
int s[me][me], hor[me][me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d%d", &N, &M, &S);
    
    getchar();
    for(int i = 1; i <= N; i ++){
        int j = 0;
        while(ch = getchar_unlocked(), ch != '\n'){
            j ++;
            hor[i][j] = hor[i][j - 1] + (ch == 'X');
            s[i][j] = s[i - 1][j] + hor[i][j];
        }
    }
 
    long long all = 0;
    for(int i = 1; i + S - 1 <= N; i ++)
        for(int j = 1; j + S - 1 <= M; j ++)
            all += s[i + S - 1][j + S - 1] - s[i - 1][j + S - 1] - s[i + S - 1][j - 1]
            + s[i - 1][j - 1];
    
    printf("%.6lf\n", 1. * all / (N - S + 1) / (M - S + 1));
    
    return 0;
}
