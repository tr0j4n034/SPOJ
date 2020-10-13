#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int g, b;
    double x, y, z, ans;
    while(cin >> g >> b)
    {
        if(g==-1 && b==-1)
            break;
        if(g==0||b==0)
            cout << max(g,b) << endl;
        else
        {
            x=min(g,b);
            x=x+1;
            y=max(g,b);
            ans=y/x;
            cout << ceil(ans) << endl;
        }
    }
 
}