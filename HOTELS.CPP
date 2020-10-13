    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define fast ios_base::sync_with_stdio(0);cin.tie(0);
    #define ll long long
    #define endl "\n"
    #define TEST int t;cin >> t;while(t--)
     
    int main()
    {
        ll n, money, sum=0, k=0, x=INT_MIN, c=1;
        cin >> n >> money;
        ll arr[n];
        for(ll i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        for(ll i=0;i<n;i++)
        {
            sum=arr[i]+sum;
            k++;
            while(sum>money)
            {
                sum=sum-arr[i+1-k];
                k--;
            }
            if(sum==money)
            {
                c=0;
                cout << money << endl;
            }
            x=max(sum,x);
        }
        if(c==1)
            cout << x << endl;
    }
     