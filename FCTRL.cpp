#include<iostream>
#include<math.h>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,ans=0, i=1;
        cin >> n;
        while(pow(5,i)<=n)
        {
            int x=n/pow(5,i);
            ans=ans+x;
            i++;
        }
        cout << ans << endl;
    }
}