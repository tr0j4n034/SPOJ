#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007
#define For(i,a,b) for(i=a;i<b;i++)
 
 
int gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
// Driver Code
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b, x, y;
        cin >> a >> b;
        ll divby=gcd(a,b);
        x=b/divby;
        y=a/divby;
        cout << x << " " <<  y << endl;
 
    }
 
}