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

const int me = 1000;

int T, X, Y;
int dis[me + 1][me + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i <= me; i ++)
        for(int j = 1; j <= me; j ++)
            dis[i][j] = -1;
    dis[1][1] = 0;
    
    queue<pair<int, int>> Q;
    Q.push(make_pair(1, 1));
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        int x = cur.first;
        int y = cur.second;
        
        for(int i = -2; i <= 2; i ++)
            for(int j = -2; j <= 2; j ++)
                if(i * i + j * j == 5)
                    if(x + i > 0 && x + i <= me && y + j > 0 && y + j <= me)
                        if(dis[x + i][y + j] == -1){
                            dis[x + i][y + j] = dis[x][y] + 1;
                            Q.push(make_pair(x + i, y + j));
                        }
    }
    
    cin >> T;
    while(T --){
        cin >> X >> Y;
        cout << dis[X][Y] << endl;
    }
    
    return 0;
}
