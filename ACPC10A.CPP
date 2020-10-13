#include<bits/stdc++.h>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl "\n"
 
int main()
{
	fast;
    int a1,a2,a3;
    while(cin >> a1 >> a2 >> a3)
    {
        if(a1==0 && a2==0 && a3==0)
            break;
        if(a2-a1==a3-a2)
        {
            cout << "AP " << 2*a3-a2 << endl;
        }
        else if(a2/a1==a3/a2)
        {
            cout << "GP " << a3*a3/a2 << endl;
        }
    }
}