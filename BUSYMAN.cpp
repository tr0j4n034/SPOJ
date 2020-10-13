    /************
    Author :- Profesor(Abhishek)
    23.09.2020  17.45.06
    **********/
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fast ios_base::sync_with_stdio(0);cin.tie(0);
    #define endl "\n"
    #define for0(i, n) for (int i = 0; i < n; i++)
    #define for1(i, n) for (int i = 1; i < n; i++)
    #define loop(i,a,b) for(int i=a;i<b;i++)
    #define loopr(i,a,b) for(int i=a;i>b;i--)
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
     
    bool cmp(const pair<int, int> &a,const pair<int, int> &b)
    {
        return (a.second < b.second);
    }
     
    int main()
    {
         ll t=1;
         cin >> t;
         while(t--)
        {
             ll n;
             cin >> n;
             vector<pair<int, int>> vec;
             ll start, finish;
             for0(i, n)
             {
                 cin >> start >> finish;
                 vec.push_back(mp(start, finish));
             }
             sort(all(vec), cmp);
             
        //       for (int i=0; i<n; i++) 
        // { 
        //     // "first" and "second" are used to access 
        //     // 1st and 2nd element of pair respectively 
        //     cout << vec[i].first << " "
        //          << vec[i].second << endl; 
        // } 
        
             ll cnt = 1;
     
             ll fin = vec[0].se;
             for (i = 1; i < n;i++)
             {
                 if(vec[i].fi >= fin)
                 {
                     cnt++;
                     fin = vec[i].se;
                 }
             }
             cout << cnt << endl;
        }
     
     
       // cout << endl << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
        return 0;
    } 