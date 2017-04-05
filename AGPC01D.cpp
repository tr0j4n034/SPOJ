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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bitset>

using namespace std;

const int me = 2025;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int T, N, M;
    int cnt[2][150];
    
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> N >> M;
        string s;
        for(int i = 0; i < 2; i ++)
            for(int j = 0; j < 150; j ++)
                cnt[i][j] = 0;
        for(int i = 0; i < 2; i ++){
            cin >> s;
            for(char j : s)
                cnt[i][j] ++;
        }
        int result = 123456;
        for(int i = 'a'; i <= 'z'; i ++)
            if(cnt[1][i] != 0)
                result = min(result, cnt[0][i] / cnt[1][i]);
        cout << result << endl;
    }
    
    return 0;
}
