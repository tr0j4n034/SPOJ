#include<iostream>
#include<algorithm>
#include<stack>
 
using namespace std ;
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
 
int main ()
{
    fast;
    int n, i;
    while(cin >> n&& n!=0)
    {
        int arr[n], c;
        int invP[n];
        for(i=0;i<n;i++)
        {
            cin >> arr[i];
            invP[arr[i]-1]=i+1;
 
        }
 
 
        for(i=0;i<n;i++)
        {
            if(invP[i]!=arr[i])
            {
                c=1;
                break;
            }
            else
                c=0;
        }
        if(c==0)
            cout << "ambiguous" << endl;
        else if(c==1)
            cout << "not ambiguous" << endl;
 
    }
}