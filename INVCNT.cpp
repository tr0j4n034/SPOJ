#include<bits/stdc++.h>
#define ll long long int
#define N 10000001
using namespace std;
 
void update(ll* BIT, ll v){
  for(;v <= N; v += v&(-v))
    BIT[v]++;
}
 
ll query(ll* BIT, ll v){
  ll ans = 0;
  for(;v > 0; v -= v&(-v))
    ans += BIT[v];
  return ans;
}
 
int main() {
  ll t,n;
  cin>>t;
 
  while(t--){
    cin>>n;
 
    ll* arr = new ll[n], *BIT = new ll[N]();
    for(ll i=0;i<n;i++)
      cin>>arr[i];
 
    ll ans = (n*(n-1))/2;
    for(int i=0;i<n;i++){
      update(BIT, arr[i]);
      ans -= query(BIT, arr[i]-1);
    }
 
    cout<<ans<<"\n";
  }
  return 0;
} 
