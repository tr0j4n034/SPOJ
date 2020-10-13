#include<bits/stdc++.h>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl "\n"
 
int main()
{
	fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << 192+((n-1)*250) << endl;
    }
}