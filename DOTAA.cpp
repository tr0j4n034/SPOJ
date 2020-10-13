#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
 
ll i,j;
 
int main()
{
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        int no_of_heroes, no_of_towers, damage,sum=0;
        cin >> no_of_heroes >> no_of_towers >> damage;
        int health[no_of_heroes];
        for(i=0;i<no_of_heroes; i++)
        {
            cin >> health[i];
            if(health[i]>damage)
            {
                if(health[i]%damage==0)
                {
                    sum=sum+(health[i]/damage-1);
                }
                else
                {
                    sum=sum+health[i]/damage;
                }
            }
        }
        if(sum >= no_of_towers)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}