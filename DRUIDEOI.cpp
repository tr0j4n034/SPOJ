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

const int me = 300025;

int T, N;
int h[me], l[me], r[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        for(int i = 1; i <= N; i ++)
            scanf("%d", &h[i]);
        for(int i = 1; i <= N; i ++)
            h[i + N] = h[i];
        for(int i = 1; i <= N; i ++)
            h[i + N + N] = h[i];
        stack<pair<int, int>> S;
        for(int i = N + N + N; i >= N; i --){
            while(!S.empty() && S.top().first <= h[i])
                S.pop();
            if(i <= N + N){
                if(S.empty())
                    r[i] = -1;
                else if(S.top().second >= N + N + i)
                    r[i] = -1;
                else if(S.top().second > N + N)
                    r[i] = S.top().second - N - N;
                else r[i] = S.top().second - N;
            }
            S.push(make_pair(h[i], i));
        }
        while(!S.empty())
            S.pop();
        for(int i = 1; i <= N + N; i ++){
            while(!S.empty() && S.top().first <= h[i])
                S.pop();
            if(i > N){
                if(S.empty())
                    l[i] = -1;
                else if(S.top().second <= i - N)
                    l[i] = -1;
                else if(S.top().second <= N)
                    l[i] = S.top().second;
                else l[i] = S.top().second - N;
            }
            S.push(make_pair(h[i], i));
        }
        for(int i = N + 1; i <= N + N; i ++)
            printf("%d %d\n", l[i], r[i]);
    }
    
    return 0;
}
