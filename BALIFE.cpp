    /************
    Author :- Profesor(Abhishek)
    25.09.2020  11.23.42
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
        ll n;
        while (cin >> n)
        {
            if (n == -1) return 0;
            ll arr[n], sum = 0, max_diff = 0;
            for0(i, n)
            {
                cin >> arr[i];
                sum += arr[i];
            }
            if(sum % n != 0)
            {
                cout << "-1" << endl;
                continue;
            }
            else
            {
                ll load = sum / n;
                 ll diff = 0;
                for (ll i = 0; i < n; i++)
                {
                   
                    diff += (arr[i] - load);
                    max_diff = max(max_diff, abs(diff));
                }
            }
            cout << max_diff << endl;
            }
    } 