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

int T, N, Q;
int starting[me], ending[me], id[me];
string name[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        for(int i = 1; i <= N; i ++){
            int h, m;
            scanf("%d:%d", &h, &m);
            starting[i] = 60 * h + m;
            scanf("%d:%d", &h, &m);
            ending[i] = 60 * h + m;
            if(ending[i] <= starting[i])
                ending[i] += 1440;
            for(int j = starting[i]; j < ending[i]; j ++)
                id[(j >= 1440) ? j - 1440 : j] = i;
            cin >> name[i];
        }
        scanf("%d", &Q);
        while(Q --){
            int h, m;
            scanf("%d:%d", &h, &m);
            int now = 60 * h + m;
            int result = -1;
            for(int i = (now + 1) % 1440; ; i = (i + 1) % 1440)
                if(id[i] != id[now]){
                    result = id[i];
                    break;
                }
            cout << name[result] << endl;
        }
    }
    
    return 0;
}
