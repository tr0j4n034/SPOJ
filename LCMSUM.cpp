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
 
const ll MAXN = (ll)1e6;
 
ll i, j, k;
 
vll LCM(MAXN+1);
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
 
    for(i = 1;i <= MAXN; i++){
		for( j = i; j <= MAXN; j+=i){
			LCM[j] += (i*phi[i]);
		}
    }
}
 
 
 
int main()
{
    phi_1_to_n();
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
//        for(i=1; i*i<n; i++)
//        {
//            if(n%i==0)
//            {
//                summation+=(i*phi[i]);
//            }
//        }
//        summation+=n*phi[n];
//        summation++;
//        cout << summation * n /2 << endl;
        ll ans = LCM[n]+1;
        ans*=n;
        ans/=2;
        cout << ans << endl;
    }
 
    return 0;
}