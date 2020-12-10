// Created by Pranav Gupta on 5/8/18

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
typedef long long ll;

ll dp[20][180][2];
bool isPrime[200];

void init(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(ll i=2;i*i<200;i++){
        if(isPrime[i])
            for(ll j=i*i;j<200;j+=i)
                isPrime[j] = false;
    }
}
void getDigits(ll a,vector<ll> &v){
    while(a){
        v.pb(a%10);
        a /= 10;
    }
}

ll helper(ll idx,ll sum,ll tight,vector<ll> &digit){
    if(idx==-1){
        return isPrime[sum];
    }
    if(dp[idx][sum][tight]!=-1)
        return dp[idx][sum][tight];

    ll k = tight ? digit[idx] : 9;
    ll ans = 0;
    for(ll i=0;i<=k;i++){
        ll newTight = (digit[idx]==i) ? tight : 0;
        ans += helper(idx-1,sum+i,newTight,digit);
    }
    return dp[idx][sum][tight] = ans;
}
ll solve(ll a,ll b){
    memset(dp,-1,sizeof(dp));
    vector<ll> da,db;

    getDigits(a-1,da);
    getDigits(b,db);

    ll x = helper(db.size()-1,0,1,db);
    memset(dp,-1,sizeof(dp));
    ll y = helper(da.size()-1,0,1,da);
    return x-y;
}
int main(){
    ll t;
    cin >> t;
    init();
    while(t--){
        ll a,b;
        cin >> a >> b;
        cout << solve(a,b) << endl;
    }
}