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

const int me = 1025;

int T, N, M;
int cost[me], par[me];

int Find(int x){
    return x == par[x] ? x : par[x] = Find(par[x]);
}
void Union(int x, int y){
    int rootx = Find(x);
    int rooty = Find(y);
    
    if(rootx == rooty)
        return;
    if(rand() & 1)
        swap(rootx, rooty);
    par[rootx] = rooty;
    cost[rooty] += cost[rootx];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> N >> M;
        for(int i = 1; i <= N; i ++){
            cin >> cost[i];
            par[i] = i;
        }
        while(M --){
            int u, v;
            cin >> u >> v;
            Union(u, v);
        }
        vector<int> result;
        for(int i = 1; i <= N; i ++)
            if(i == Find(i))
                result.push_back(cost[i]);
        sort(result.begin(), result.end());
        cout << "Case " << c + 1 << ": ";
        cout << (int)result.size() << endl;
        for(int i = 0; i < (int)result.size(); i ++){
            cout << result[i];
            if(i < (int)result.size() - 1)
                cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
