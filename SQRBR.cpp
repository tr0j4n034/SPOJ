#include<bits/stdc++.h>
using namespace std;
 
int solve(unordered_map<int,int> m, int o, int c,int n, int** dp) {
  if(c == n)
    return 1;
 
  if(dp[o][c] > -1)
    return dp[o][c];
 
  if(o <= c) {
    dp[o][c] = solve(m, o + 1, c, n, dp);
    return dp[o][c];
  }
 
  if(o == n) {
    dp[o][c] = ((m.count(o+c+1) == 0) ? solve(m,o,c+1,n,dp) : 0 );
    return dp[o][c];
  }
 
  int l1,l2;
  l1 = ((m.count(o+c+1) == 0) ? solve(m,o,c+1,n,dp) : 0 );
  l2 = solve(m,o+1,c,n,dp);
  dp[o][c] = l1+l2;
  return l1+l2;
}
 
int main() {
  int t,n,k,p;
  cin>>t;
  while(t--) {
    cin>>n>>k;
    unordered_map<int,int> m;
    while(k--){
      cin>>p;
      m[p] = 1;
    }
 
    if(m.count(0) > 1){
      cout<<"0\n";
      continue;
    }
 
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
      dp[i] = new int[n+1];
      for(int j=0;j<=n;j++)
        dp[i][j] = -1;
    }
 
    cout<<solve(m,0,0,n,dp)<<"\n";
  }
  return 0;
} 
