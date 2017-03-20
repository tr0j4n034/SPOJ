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
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 10025;

int N, M;
int result, counter;
int in[me], used[me];
vector<int> v[me];

void dfs(int node){
    used[node] = 1;
    counter ++;
    for(int i : v[node]){
        if(!used[i])
            dfs(i);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 1; i <= M; i ++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b] ++;
    }
    //int smallest = *min_element(in + 1, in + N + 1);
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++)
            used[j] = 0;
        counter = 0;
        dfs(i);
        result = max(result, counter);
    }
    cout << result << endl;
    
    return 0;
}