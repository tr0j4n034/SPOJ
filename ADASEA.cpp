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

const int me = 1025;

int T, N, M;
int cnt;
char ch;
char s[me][me], used[me][me];

int good(int x, int y){
    return x > 0 && y > 0 && x <= N && y <= M;
}
void dfs(int x, int y){
    used[x][y] = 1;
    cnt ++;
    for(int i = -1; i < 2; i ++)
        for(int j = -1; j < 2; j ++)
            if(i * i + j * j == 1)
                if(good(x + i, y + j) && !used[x + i][y + j] && s[x + i][y + j] == '#'){
                    dfs(x + i, y + j);
                }
}
long long gcd(long long a, long long b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    
    while(T --){
        scanf("%d%d", &N, &M);
        getchar();
        for(int i = 1; i <= N; i ++){
            int j = 1;;
            while((ch = getchar()) != '\n'){
                s[i][j ++] = ch;
            }
        }
        long long p = 0;
        long long q = N * M;
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= M; j ++)
                used[i][j] = 0;
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= M; j ++)
                if(!used[i][j] && s[i][j] == '#'){
                    cnt = 0;
                    dfs(i, j);
                    p += 1LL * cnt * cnt;
                }
        long long g = gcd(p, q);
        p /= g, q /= g;
        if(q == 1)
            cout << p << endl;
        else cout << p << " / " << q << endl;
    }
    
    return 0;
}
