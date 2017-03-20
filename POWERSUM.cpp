#include <bits/stdc++.h>
 
using namespace std;
 
const int me = 10025;
const int mod = 1000000007;
 
int t, n, x;
int pw[me];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
 
    pw[0] = 1;
    for(int i = 1; i < me; i ++)
        pw[i] = 2LL * pw[i - 1] % mod;
 
    cin >> t;
    while(t --){
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i ++){
            cin >> x;
            sum = (sum + x) % mod;
        }
        cout << 1LL * sum * pw[n - 1] % mod << endl;
    }
 
    return 0;
}