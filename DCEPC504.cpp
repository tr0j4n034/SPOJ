    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define pb push_back
    #define PI 3.1415926535897932384626
    #define boost ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
    #define MOD 1000000007
    #define endl "\n"
 
//    string complement_string(string s)
//    {
//        int i;
//        string complement="";
//        for(i=0;i<s.length();i++)
//        {
//            if(s[i]=='0')
//                s[i]='1';
//            else if(s[i]=='1')
//                s[i]='0';
//            complement+=s[i];
//        }
//        return complement;
//
//    }
//
//    string main_string(int n)
//    {
//        int i;
//        string s = "0";
//        for(i=0;i<n;i++)
//        {
//            s+=complement_string(s);
//        }
//        return s;
 
//    }
    int main()
    {
		boost;
        long long t;
        cin >> t;
        while(t--)
        {
            int c=0;
            long long n, k;
            cin >> k >> n;
 
            if(n==1)
                cout << "Male" << endl;
            else if(n==2)
                cout << "Female" << endl;
            else{
 
            n=n-1;
 
            while(n>1)
            {
 
                if(n%2!=0)
                {
                    c++;
                    n=n-1;
                }
                n=n/2;
 
            }
             if(c%2==0)
                    cout << "Female" << endl;
                else
                    cout << "Male" << endl;
 
 
 
            }
        }
    }