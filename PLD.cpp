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

int N, K;
char s[me];
int pw[2][me], h[2][2][me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    pw[0][0] = pw[1][0] = 1;
    for(int i = 0; i < 2; i ++)
        for(int j = 1; j < me; j ++)
            pw[i][j] = 1LL * pw[i][j - 1] * muls[i] % mods[i];
    
    scanf("%d %s", &K, s);
    N = (int)strlen(s);
    
    for(int i = 0; i < N; i ++)
        s[i] -= 'a' - 1;
    
    for(int i = 0; i < N; i ++){
        if(i == 0){
            h[0][0][i] = s[i];
            h[0][1][i] = s[i];
        }
        else if(i < K){
            h[0][0][i] = (1LL * h[0][0][i - 1] * muls[0] % mods[0] + s[i]) % mods[0];
            h[0][1][i] = (1LL * h[0][1][i - 1] * muls[1] % mods[1] + s[i]) % mods[1];
        }
        else{
            h[0][0][i] = (h[0][0][i - 1] - 1LL * s[i - K] * pw[0][K - 1] % mods[0] + mods[0]) % mods[0];
            h[0][1][i] = (h[0][1][i - 1] - 1LL * s[i - K] * pw[1][K - 1] % mods[1] + mods[1]) % mods[1];
            //cout << "when reduced i = " << i << " --> " << h[0][0][i] << " vs " << h[0][1][i] << endl;
            h[0][0][i] = (1LL * h[0][0][i] * muls[0] % mods[0] + s[i]) % mods[0];
            h[0][1][i] = (1LL * h[0][1][i] * muls[1] % mods[1] + s[i]) % mods[1];
        }
    }
    for(int i = N - 1; i >= 0; i --){
        if(i == N - 1){
            h[1][0][i] = s[i];
            h[1][1][i] = s[i];
        }
        else if(i >= N - K){
            h[1][0][i] = (1LL * h[1][0][i + 1] * muls[0] % mods[0] + s[i]) % mods[0];
            h[1][1][i] = (1LL * h[1][1][i + 1] * muls[1] % mods[1] + s[i]) % mods[1];
        }
        else{
            h[1][0][i] = (h[1][0][i + 1] - 1LL * s[i + K] * pw[0][K - 1] % mods[0] + mods[0]) % mods[0];
            h[1][1][i] = (h[1][1][i + 1] - 1LL * s[i + K] * pw[1][K - 1] % mods[1] + mods[1]) % mods[1];
            //cout << "when reduced i = " << i << " --> " << h[0][0][i] << " vs " << h[0][1][i] << endl;
            h[1][0][i] = (1LL * h[1][0][i] * muls[0] % mods[0] + s[i]) % mods[0];
            h[1][1][i] = (1LL * h[1][1][i] * muls[1] % mods[1] + s[i]) % mods[1];
        }
    }
    
    //for(int i = 0; i < N; i ++)
    //    cout << i << " --> " << h[0][0][i] << " vs " << h[0][1][i] << endl;
    //for(int i = 0; i < N; i ++)
    //   cout << i << " --> " << h[1][0][i] << " vs " << h[1][1][i] << endl;
    
    int answer = 0;
    for(int i = K - 1; i < N; i ++)
        if(h[0][0][i] == h[1][0][i - K + 1] && h[0][1][i] == h[1][1][i - K + 1])
            answer ++;
    
    cout << answer << endl;
    
    return 0;
}
