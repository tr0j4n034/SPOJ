    /************
    Author :- Profesor(Abhishek)
    25.09.2020  15.42.18
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
    int main()
    {
         ll t=1;
         cin >> t;
         while(t--)
        {
             ll w, h, n;
             cin >> w >> h >> n;
             if(n == 0)
             {
                 cout << w * h << endl;
                 continue;
             }
             ll width[n], height[n], max1=0 , max2 = 0;
             for (i = 0; i < n;i++)
            {
                 cin >> width[i] >> height[i];
            }
            sort(width, width + n);
            sort(height, height + n);
            for (i = 1; i < n; i++)
            {
                max1 = max(max1, width[i] - width[i - 1] -1);
                max2 = max(max2, height[i] - height[i - 1] -1);
                // cout << max1 << " " << max2 << endl;
            }
            max1 = max(max1, width[0] -1 );
            max1 = max(max1, w - width[n-1]);
            max2 = max(max2, height[0] - 1);
            max2 = max(max2, h- height[n-1]);
     
            cout << max1 * max2 << endl;
        }
     
     
       // cout << endl << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
        return 0;
    } 