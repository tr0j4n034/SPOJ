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

const int me = 10025;
const int muls[] = {23, 43};
const int mods[] = {715225741, 1000000007};

int T, N, M;
vector<int> edges[me];
map<pair<int, int>, vector<int> > m;

template <class T> void FastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    FastInput(T);
    
    for(int c = 0; c < T; c ++){
        FastInput(N);
        FastInput(M);
        
        for(int i = 1; i <= N; i ++)
            edges[i].clear();
        m.clear();
        
        for(int i = 1; i <= N; i ++)
            edges[i].push_back(i);
        while(M --){
            int u, v;
            FastInput(u);
            FastInput(v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for(int i = 1; i <= N; i ++){
            sort(edges[i].begin(), edges[i].end());
            int h1 = 0, h2 = 0;
            for(int j : edges[i]){
                h1 = (1LL * h1 * muls[0] % mods[0] + j) % mods[0];
                h2 = (1LL * h2 * muls[1] % mods[1] + j) % mods[1];
            }
            m[make_pair(h1, h2)].push_back(i);
        }
        
        pair<int, int> result(N + 1, N + 1);
        for(auto i : m){
            if((int)i.second.size() < 2)
                continue;
            sort(i.second.begin(), i.second.end());
            result = min(result, make_pair(i.second[0], i.second[1]));
        }
        
        printf("Case #%d:\n", c + 1);
        if(result.first == N + 1)
            printf("No twins\n");
        else printf("%d %d\n", result.first, result.second);
    }
    
    
    return 0;
}
