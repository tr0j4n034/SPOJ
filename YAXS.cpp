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

int t, n, x, ans;
int cnt[5];

void go(int mask, vector<int> cnt){
    if(__builtin_popcount(mask) == 1){
        for(int i = 0; i < 5; i ++)
            if(mask & (1 << i)){
                ans = max(ans, cnt[i]);
                return;
            }
    }
    for(int i = 0; i < 5; i ++)
        if(mask & (1 << i))
            for(int j = i + 1; j < 5; j ++)
                if(mask & (1 << j)){
                    int to = ((i + 1) ^ (j + 1));
                    if(to > 5)
                        continue;
                    int make = min(cnt[i], cnt[j]);
                    if(make < 1)
                        continue;
                    vector<int> copied = cnt;
                    copied[i] -= make;
                    copied[j] -= make;
                    copied[to - 1] += make;
                    int new_mask = mask;
                    new_mask ^= (1 << i);
                    new_mask ^= (1 << j);
                    new_mask |= (1 << (to - 1));
                    go(new_mask, copied);
                }
    for(int i = 0; i < 5; i ++)
        if(mask & (1 << i))
            ans = max(ans, cnt[i]);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    for(int c = 0; c < t; c ++){
        scanf("%d", &n);
        fill(cnt, cnt + 5, 0);
        for(int i = 0; i < n; i ++){
            scanf("%d", &x);
            cnt[x - 1] ++;
        }
        ans = 0;
        go(31, vector<int>(cnt, cnt + 5));
        printf("Case %d: %d\n", c + 1, ans);
    }
    
    return 0;
}
