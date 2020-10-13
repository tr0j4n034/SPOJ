/************
 
   Author :- Profesor(Abhishek)
   2020-08-30-21.05.45
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
 
 
vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, true);
    mark[0]=mark[1]=false;
    vector<long long> primes;
    primes.emplace_back(2);
    for (long long i = 3; i <= lim; i+=2) {
        if (mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = false;
        }
    }
 
    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
 
 
int main()
{
	fast;
    ll t;
    cin >>t;
    while(t--)
    {
        ll l, r;
        cin >> l >> r;
        vector<bool>p = segmentedSieve(l ,r);
        for(i=l;i<=r;i++)
        {
            if(p[i-l])
                cout << i << endl;
        }
        cout << endl;
    }
 
    return 0;
}