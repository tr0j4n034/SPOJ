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

const int me = 125;

int T, N;
string s[me];
int used[me][me];
vector<int> v[me], g[me];

void dfs(int start, int node){
    used[start][node] = 1;
    for(int i : v[node]){
        if(!used[start][i])
            dfs(start, i);
    }
}
void dfs2(int node){
    used[0][node] = 1;
    for(int i : g[node]){
        if(!used[0][i])
            dfs2(i);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    for(int cases = 0; cases < T; cases ++){
        cin >> N;
        for(int i = 1; i <= N; i ++){
            cin >> s[i];
            s[i] = "$" + s[i];
        }
        for(int i = 0; i <= N; i ++)
            for(int j = 1; j <= N; j ++)
                used[i][j] = 0;
        for(int i = 1; i <= N; i ++)
            v[i].clear(), g[i].clear();
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= N; j ++)
                if(s[i][j] == 'Y')
                    v[i].push_back(j);
        for(int i = 1; i <= N; i ++)
            dfs(i, i);
        for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= N; j ++)
                if(i != j && used[i][j] && used[j][i])
                    g[i].push_back(j);
        int answer = 0;
        for(int i = 1; i <= N; i ++)
            if(!used[0][i])
                dfs2(i), answer ++;
        cout << answer << endl;
    }
    
    return 0;
}
