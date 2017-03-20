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

const int me = 125;

int t;
int cnt[2][me];
char ch;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    getchar();
    while(t --){
        for(int i = 0; i < 2; i ++)
            for(int j = 'a'; j <= 'z'; j ++)
                cnt[i][j] = 0;
        char last = '$';
        int l = 0;
        while((ch = getchar()) != ' '){
            if(ch != last){
                cnt[0][last] = max(cnt[0][last], l);
                l = 1;
            }
            else l ++;
            last = ch;
        }
        cnt[0][last] = max(cnt[0][last], l);
        
        last = '$';
        l = 0;
        while((ch = getchar()) != '\n'){
            if(ch != last){
                cnt[1][last] = max(cnt[1][last], l);
                l = 1;
            }
            else l ++;
            last = ch;
        }
        cnt[1][last] = max(cnt[1][last], l);
        
        int ans = 0;
        for(int i = 'a'; i <= 'z'; i ++)
            ans = max(ans, cnt[0][i] + cnt[1][i]);
        printf("%d\n", ans);
    }
    
    return 0;
}
