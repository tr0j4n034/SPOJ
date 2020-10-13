#include<iostream>
#include<algorithm>
#include<stack>
 
using namespace std ;
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
 
int main ()
{
    int t, i;
    cin >> t;
    while(t--)
    {
        ll first_third,last_third,sum;
        cin >> first_third >> last_third >> sum;
        ll n= (sum*2)/(first_third+last_third);
        cout << n << endl;
        ll d=(last_third-first_third)/(n-5);
//        cout << d << endl;
        ll first_term=first_third-2*d;
        ll x=first_term;
        for(i=0;i<n;i++)
        {
            cout << x << " ";
            x=x+d;
        }
        cout << endl;
 
 
    }
}