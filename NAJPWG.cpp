/************
 
   Author :- Profesor(Abhishek)
   2020-08-24-15.32.01
**********/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define forr(i,a,b) for(ll i=a;i>=b;i--)
#define forit(it,x) for (auto it=(x).begin();it!=(x).end(); it++)
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sll set<ll>
#define vll vector<ll>
#define msl map<string,ll>
#define mll map<ll,ll>
 
const ll MAXN = (ll)1e5;
 
ll i, j, k;
 
vector<ll> phi(MAXN+1);
 
 
 
void phi_1_to_n() {
 
    phi[0] = 0;
    phi[1] = 1;
    for ( i = 2; i <= MAXN; i++)
        phi[i] = i;
 
    for (i = 2; i <= MAXN; i++) {
        if (phi[i] == i) {
            for (j = i; j <= MAXN; j+=i)
                phi[j] -= phi[j] / i;
        }
    }
 
}
 
ll binary_exponentation(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
 
 
 
int main()
{
    phi_1_to_n();
    fast;
    ll t,x=0;
    cin >> t;
    ll ans[MAXN+1];
    for(i=1;i<=MAXN;i++)
    {
        ans[i]=ans[i-1]+(i-phi[i]);
    }
    while(t--)
    {
        x++;
        ll n ;
        cin >> n;
        cout << "Case " << x << ": " << ans[n] << endl;
 
 
    }
 
}