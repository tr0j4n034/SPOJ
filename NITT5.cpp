#include <bits/stdc++.h>
 
using namespace std;
 
const int me = 1025;
 
int t, n, m = 9;
int c[me][me], pw[2][me];
string s;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
 
    cin >> t;
    while(t --){
        cin >> s;
        n = (int)s.size();
        s = "$" + s;
        pw[0][0] = pw[1][0] = 1 % m;
        for(int i = 1; i < me; i ++){
            pw[0][i] = 2LL * pw[0][i - 1] % m;
            pw[1][i] = 10LL * pw[1][i - 1] % m;
        }
        for(int i = 0; i <= n; i ++)
            for(int j = 0; j <= i; j ++){
                if(j == 0)
                    c[i][j] = 1;
                else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
            }
        int ans = 0;
        for(int i = 1; i <= n; i ++)
            for(int j = 0; j + i <= n; j ++){
                int can = 1LL * pw[0][i - 1] * c[n - i][j] % m * pw[1][j] % m * (s[i] - '0') % m;
                ans = (ans + can) % m;
            }
        cout << ans << endl;
    }
 
    return 0;
} 