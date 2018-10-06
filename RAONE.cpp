// Created by Pranav Gupta on 5/8/18

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
typedef long long ll;

ll dp[20][180][180][2];

void getDigits(ll a,vector<int> &v){
    while(a){
        v.pb(a%10);
        a /= 10;
    }
}
ll helper(int idx,int sume,int sumo,int tight,vector<int> &digit){
    if(idx==-1){
        return (sume-sumo)==1;
    }
    if(dp[idx][sume][sumo][tight]!=-1)
        return dp[idx][sume][sumo][tight];
    int currIdx = idx+1;
    int k = tight ? digit[idx] : 9;
    ll ans = 0;
    for(int i=0;i<=k;i++){
        int newTight = (digit[idx]==i) ? tight : 0;
        if(currIdx&1)
            ans += helper(idx-1,sume,sumo+i,newTight,digit);
        else
            ans += helper(idx-1,sume+i,sumo,newTight,digit);
    }
    return dp[idx][sume][sumo][tight] = ans;
}
ll solve(ll a,ll b){
    memset(dp,-1,sizeof(dp));
    vector<int> da,db;

    getDigits(a-1,da);
    getDigits(b,db);

    ll x = helper(db.size()-1,0,0,1,db);
    memset(dp,-1,sizeof(dp));
    ll y = helper(da.size()-1,0,0,1,da);
    return x-y;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << solve(a,b) << endl;
    }
}