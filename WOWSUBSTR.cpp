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

const int me = 500025;
const int mod = 100007;

int T, N;
int cnt[123];
char ch;
char s[me];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d", &T);
    getchar();
    
    for(int c = 0; c < T; c ++){
        N = 0;
        while(ch = getchar_unlocked(), ch != '\n')
            s[++N] = ch;
        
        for(int i = 'a'; i <= 'z'; i ++)
            cnt[i] = 0;
        int ptr = 1, ans = 0;
        for(int i = 1; i <= N; i ++){
            while(ptr <= N){
                cnt[s[ptr]] ++;
                if(cnt[s[ptr]] == 2){
                    break;
                }
                ptr ++;
            }
            cnt[s[ptr]] --;
            cnt[s[i]] --;
            int l = ptr - i;
            ans = (ans + l * (l + 1) / 2) % mod;
        }
        printf("Case %d: %d\n", c + 1, ans);
    }
    
    return 0;
}
