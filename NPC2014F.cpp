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

const int me = 100025;
const int ALPHA = 125;

int n, m;
int cnt[ALPHA], cur[ALPHA];
char s[me];

bool CanRemove(int pos){
    cur[s[pos]] --;
    bool ok = 1;
    for(int i = 'a'; i <= 'z' && ok; i ++){
        ok &= cur[i] >= cnt[i];
    }
    cur[s[pos]] ++;
    return ok;
}
bool Good(){
    for(int i = 'a'; i <= 'z'; i ++)
        if(cur[i] < cnt[i])
            return false;
    return true;
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%d", &m);
    while(m --){
        int x;
        char ch;
        scanf("%d %c", &x, &ch);
        cnt[ch] = x;
    }
    int ans = n + 1, ptr = 1;
    for(int i = 1; i <= n; i ++){
        cur[s[i]] ++;
        while(ptr <= n && CanRemove(ptr)){
            cur[s[ptr]] --;
            ptr ++;
        }
        if(Good())
            ans = min(ans, i - ptr + 1);
    }
    if(ans > n)
        printf("Andy rapopo\n");
    else printf("%d\n", ans);
    
    return 0;
}
