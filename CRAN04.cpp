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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1000025;

int t, n, k;
char s[me];
int boys[me];

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d%d", &n, &k);
        scanf(" %s", s);
        if(k == 0){
            long long ans = 0;
            int l = 0;
            for(int i = 0; i < n; i ++){
                if(s[i] == '1')
                    ans += 1LL * l * (l + 1) / 2, l = 0;
                else l ++;
            }
            ans += 1LL * l * (l + 1) / 2;
            printf("%lld\n", ans);
            continue;
        }
        for(int i = 1; i <= n; i ++)
            boys[i] = boys[i - 1] + (s[i - 1] == '1');
        boys[n + 1] = -1;
        int ptr1 = 1, ptr2 = 1;
        long long ans = 0;
        for(int i = 1; i <= n; i ++){
            while(ptr1 < n && boys[ptr1] - boys[i - 1] < k)
                ++ptr1;
            while(ptr2 < n && boys[ptr2 + 1] - boys[i - 1] <= k)
                ++ptr2;
            if(boys[ptr1] - boys[i - 1] == k && boys[ptr2] - boys[i - 1] == k)
                ans += ptr2 - ptr1 + 1;
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}