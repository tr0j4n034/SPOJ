/************
 
   Author :- Profesor(Abhishek)
   2020-08-26-18.57.36
**********/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define forr(i,a,b) for(ll i=a;i>=b;i--)
#define forit(it,x) for (auto it=(x).begin();it!=(x).end(); it++)
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define eb emplace_back
#define pb push_backbig
#define mp make_pair
#define fi first
#define se second
#define sll set<ll>
#define vll vector<ll>
#define msl map<string,ll>
#define mll map<ll,ll>
 
const ll big = 1e9+7;
 
ll binary_exponentation(ll a, ll n) {
	if(n == 0)
		return 1;
	if(n == 1)
		return a%big;
	ll r = binary_exponentation(a, n/2);
	if(n % 2 == 0) {
		return (r%big * r%big)%big;
	}
	else
		return (r%big * r%big * a%big)%big;
}
 
 
ll i, j, k;
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n<3)
        {
            cout << n << endl;
            continue;
        }
 
        if(n%3==1)
        {
            cout << 4 * binary_exponentation(3 , (n-4)/3)%big << endl;
 
        }
        else if(n%3==2)
        {
 
            cout << 2 * binary_exponentation(3 , (n-2)/3)%big << endl;
        }
        else
        {
            cout <<  binary_exponentation(3 , n/3)%big << endl;
        }
    }
    return 0;
}