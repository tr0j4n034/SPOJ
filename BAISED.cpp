    /************
    Author :- Profesor(Abhishek)
    24.09.2020  12.13.49
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
        ll t;
        cin >> t;
        while(t--)
        {
            ll n;
            cin >> n;
            vll vec;
            while(n--)
            {
                string s;
                ll x;
     
                cin >> s;
                cin >> x;
                vec.push_back(x);
            }
            sort(all(vec));
            ll res = 0;
            for (i = 0; i < vec.size();i++)
            {
                res += abs(vec[i] - (i+1));
            } 
            cout << res << endl;
            vec.clear();
     
        }
    } 