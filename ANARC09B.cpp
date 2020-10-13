#include<bits/stdc++.h>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl "\n"
 
long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
long long lcm(long long a, long long b)
{
    return a*b/gcd(a,b);
}
 
int main()
{
//    fast;
    long long w, h, x, a, b;
    while(cin >> w >> h)
    {
        if(w==0 && h==0)
            break;
        else
        {
            x=lcm(w,h);
            a=x/w;
            b=x/h;
        }
        cout << a*b << endl;
    }
 
}