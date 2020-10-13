#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007
#define For(i,a,b) for(i=a;i<b;i++)
 
void georgeCantor(int n)
{
    int i = 1; // let i = numerator
    int j = 1; // let j = denominator
    int k = 1; // to keep the check of no. of terms
 
    // loop till k is not equal to n
    while (k < n)
    {
        j++ , k++;
 
        // check if k is already equal to N
        // then the first term is the required
        // rational number
        if (k == n)
            break;
 
        // loop for traversing from right to left
        // downwards diagonally
        while (j > 1 && k < n) {
            i++, j--, k++;
        }
 
        if (k == n)
           break;
 
        i++, k++;
 
        if (k == n)
           break;
 
        // loop for traversing from left
        // to right upwards diagonally
        while (i > 1 && k < n) {
            i--, j++, k++;
        }
    }
    cout << "TERM "<< n<<" IS "<< i << "/" <<j <<endl;
}
 
ll i,j;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >>n;
        georgeCantor(n);
    }
 
}