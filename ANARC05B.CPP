    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define pb push_back
    #define PI 3.1415926535897932384626
    #define boost ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
    #define MOD 1000000007
    #define forn(i,n) for(int i=0;i<n;i++)
    int n;
    int main()
    {
     boost;
     cin>>n;
     while(n)
     {
     int m,s1=1,s2=1,ans=0;
     int arr[n];
     forn(i,n)
     cin>>arr[i];
     cin>>m;
     int brr[m];
     forn(i,m)
     cin>>brr[i];
 
     int pref[n+1];
     pref[0]=0;
     pref[1]=arr[0];
     for(int i=2;i<=n;i++)
     pref[i]=pref[i-1]+arr[i-1];
 
 
     int cref[m+1];
     cref[0]=0;
     cref[1]=brr[0];
 
 
     for(int i=2;i<=m;i++)
     cref[i]=cref[i-1]+brr[i-1];
 
     for(int i=0;i<m;i++)
     {
     if(binary_search(arr,arr+n,brr[i]))
     {
     int idx=lower_bound(arr,arr+n,brr[i])-arr;
     int valx=pref[idx+1]-pref[s1-1];
     int valy=cref[i+1]-cref[s2-1];
     ans+=max(valx,valy);
     s1=idx+2;
     s2=i+2;
     }
     }
     int x=pref[n]-pref[s1-1];
     int y=cref[m]-cref[s2-1];
     ans+=max(x,y);
     cout<<ans<<endl;
     cin>>n;
     }
 
    }