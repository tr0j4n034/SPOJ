#include<bits/stdc++.h>
#include<string.h>
 
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl "\n"
 
int main()
{
    fast;
    int t,i;
    cin >> t;
    while(t--)
    {
        int ng, nm,max1=0,max2=0;
        cin >> ng >> nm;
        int arr1[ng], arr2[nm];
        for(i=0;i<ng;i++)
        {
            cin >> arr1[i];
            max1=max(arr1[i],max1);
        }
        for(i=0;i<nm;i++)
        {
            cin >> arr2[i];
            max2=max(arr2[i],max2);
        }
        if(max1>max2)
        {
            cout  << "Godzilla" << endl;
        }
        else if(max1<max2)
        {
            cout  << "MechaGodzilla" << endl;
        }
        else if(max1==max2)
        {
            cout << "Godzilla" << endl;
        }
 
    }
 
}