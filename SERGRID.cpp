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
#include <set>
#include <map>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 525;

int n, m;
int a[me][me], dis[me][me];
queue<pair<int , pair<int, int>>> Q;

void add(int x, int y, int d){
    if(x < 1 || x > n || y < 1 || y > m)
        return;
    if(dis[x][y] < d)
        return;
    dis[x][y] = d;
    Q.push(make_pair(d, make_pair(x, y)));
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 1; i <= n; i ++){
        char ch;
        int j = 0;
        while((ch = getchar()) != '\n'){
            a[i][++j] = ch - '0';
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            dis[i][j] = 1 << 30;
    dis[1][1] = 0;
    
    Q.push(make_pair(0, make_pair(1, 1)));
    while(!Q.empty()){
        auto cur = Q.front();
        int x = cur.second.first;
        int y = cur.second.second;
        Q.pop();
        if(cur.first > dis[x][y])
            continue;
        int v = a[x][y];
        add(x - v, y, cur.first + 1);
        add(x + v, y, cur.first + 1);
        add(x, y - v, cur.first + 1);
        add(x, y + v, cur.first + 1);
    }
    if(dis[n][m] == (1 << 30))
        cout << -1 << endl;
    else cout << dis[n][m] << endl;
    
    return 0;
}
