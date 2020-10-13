    #include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long int
    #define endl "\n"
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define MOD 1000000007
    #define For(i,a,b) for(i=a;i<b;i++)
     
    ll i,j;
     
    int main()
    {
    //    fast;
        int t;
        cin >> t;
        while(t--)
        {
            double a, b, c, d;
            cin >> a >> b >> c >> d;
            double s=(a+b+c+d)/2;
    //        cout << s << endl;
            double ans=(s-(double)a)*(s-(double)b)*(s-(double)c)*(s-(double)d);
    //        cout << ans << endl;
            ans=sqrt(ans);
            cout << fixed << setprecision(2) << ans << endl;
        }
    }
     