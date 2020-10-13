#include<bits/stdc++.h>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl "\n"
 
int main()
{
    int n;
    while(cin >> n)
    {
        if(n==0)
            break;
 
        int x=n*(n+1)*(2*n+1)/6;
        cout << x << endl;
 
    }
    return 0;
 
}