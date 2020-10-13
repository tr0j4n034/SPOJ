#include <bits/stdc++.h>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl "\n"
#define TEST int t;cin >> t;while(t--)
 
int main()
{
    set<int>fof;
    int t;
    cin >> t;
    int y=t;
    while(t--)
    {
        int fbfriend, n;
        cin >> fbfriend >> n;
        fof.insert(fbfriend);
        int x;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            fof.insert(x);
        }
    }
//    set<int>::iterator it;
//    for(it=fof.begin();it!=fof.end();it++)
//        cout << *it << " ";
    cout << fof.size()-y << endl;
}