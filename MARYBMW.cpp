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

const int me = 50025;

int T, N, M;
int used[me];
long long ans[me];
vector<pair<int, long long>> v[me];

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}
static long long ugetl()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    long long n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    T = uget();
    while(T --){
        N = uget(), M = uget();
        for(int i = 1; i <= N; i ++)
            v[i].clear();
        while(M --){
            int a, b;
            long long l;
            a = uget(), b = uget(), l = ugetl();
            v[a].push_back(make_pair(b, l));
            v[b].push_back(make_pair(a, l));
        }
        fill(ans, ans + me, 0);
        fill(used, used + me, 0);
        ans[1] = 1LL << 62;
        queue<int> Q;
        Q.push(1);
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            for(auto i : v[cur]){
                long long go = min(ans[cur], i.second);
                if(go > ans[i.first]){
                    ans[i.first] = go;
                    Q.push(i.first);
                }
            }
        }
        if(ans[N] == 0)
            puts("-1");
        else printf("%lld\n", ans[N]);
    }
    
    return 0;
}