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
 
const int mods[] = {715225741, 1000000007};
const int muls[] = {43, 73};
 
//const int mods[] = {1000000000, 1000000000};
//const int muls[] = {10, 10};
 
char s[me];
int pw[2][me], h[2][me];
 
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    pw[0][0] = pw[1][0] = 1;
    for(int i = 0; i < 2; i ++)
        for(int j = 1; j < me; j ++)
            pw[i][j] = 1LL * pw[i][j - 1] * muls[i] % mods[i];
    
    while(scanf("%s", s) != EOF){
        int N = (int)strlen(s);
        //for(int i = 0; i < N; i ++)
          //  s[i] -= 'a' - 1;
        pair<int, int> h1(0, 0);
        pair<int, int> h2(0, 0);
        int p1 = 1, p2 = 1;
        for(int i = 0; i < N; i ++){
            h1.first = (1LL * h1.first * muls[0] % mods[0] + s[i]) % mods[0];
            h1.second = (1LL * h1.second * muls[1] % mods[1] + s[i]) % mods[1];
            h2.first = (1LL * h2.first * muls[0] % mods[0] + s[N - i - 1]) % mods[0];
            h2.second = (1LL * h2.second * muls[1] % mods[1] + s[N - i - 1]) % mods[1];
            p1 = 1LL * p1 * muls[0] % mods[0];
            p2 = 1LL * p2 * muls[1] % mods[1];
        }
        //cout << "h1 = " << h1.first << " and " << h1.second << endl;
        //cout << "h2 = " << h2.first << " and " << h2.second << endl;
        h[0][0] = h[1][0] = s[0];
        for(int i = 1; i < N; i ++){
            h[0][i] = (1LL * s[i] * pw[0][i] % mods[0] + h[0][i - 1]) % mods[0];
            h[1][i] = (1LL * s[i] * pw[1][i] % mods[1] + h[1][i - 1]) % mods[1];
        }
        //for(int i = 0; i < N; i ++)
        //    cout << "i = " << i << " ---> " << h[0][i] << " vs " << h[1][i] << endl;cout << endl;
        pair<int, int> fh = h1;
        pair<int, int> sh(0, 0);
        int ptr = 0;
        while(h1 != h2 && ptr < N){
            sh.first = (1LL * sh.first * muls[0] % mods[0] + s[ptr]) % mods[0];
            sh.second = (1LL * sh.second * muls[1] % mods[1] + s[ptr]) % mods[1];
            h1.first = (1LL * fh.first * pw[0][ptr + 1] % mods[0] + h[0][ptr]) % mods[0];
            h1.second = (1LL * fh.second * pw[1][ptr + 1] % mods[1] + h[1][ptr]) % mods[1];
            h2.first = (1LL * sh.first * pw[0][N] % mods[0] + h[0][N - 1]) % mods[0];
            h2.second = (1LL * sh.second * pw[1][N] % mods[1] + h[1][N - 1]) % mods[1];
            //cout << "now:" << endl;
            //cout << "h1 = " << h1.first << " and " << h1.second << endl;
            //cout << "h2 = " << h2.first << " and " << h2.second << endl;
            ++ptr;
        }
        //cout << "ptr = " << ptr << endl;
        for(int i = 0; i < N; i ++)
            putchar(s[i]);
        for(int i = ptr - 1; i >= 0; i --)
            putchar(s[i]);
        putchar('\n');
    }
 
    return 0;
}