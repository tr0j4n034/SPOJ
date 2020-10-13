/************
 
   Author :- Profesor(Abhishek)
   2020-09-01-13.17.13
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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sll set<ll>
#define vll vector<ll>
#define msl map<string,ll>
#define mll map<ll,ll>
 
ll i, j, k;
 
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
 
ll find_any_solution(ll a, ll b, ll c)
{
    if(!(c%gcd(a,b)))
    {
        return 1;
    }
    else
        return 0;
}
 
int main()
{
    ll t, x=0;
    cin >> t;
    while(t--)
    {
        x++;
        ll a, b, c;
        cin >> a >> b >> c;
         cout<<"Case "<<x;
        if(find_any_solution(a, b, c))
        {
            cout <<": Yes"<<'\n';
        }
        else
            cout <<": No"<<'\n';
 
    }
    return 0;
}