#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
 
int priority(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c== '/')
        return 2;
    else if(c=='+' || c== '-')
        return 1;
    else
        return -1;
}
 
void infixtopostfix(string s)
{
    stack <int> st;
    st.push('E');
    string res="";
    for( int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push('(');
        }
        else if(s[i] == ')')
        {
            while(st.top() != 'E' && st.top() != '(')
            {
                char c=st.top();
                st.pop();
                res=res + c;
            }
            if(st.top() == '(')
            {
                st.pop();   // not added char c=st.top()????
            }
        }
        else
        {
            while(st.top()!='E' && priority(s[i]) <= priority(st.top()))
            {
                char c=st.top();
                st.pop();
                res+=c;
            }
            st.push(s[i]);
        }
 
    }
    while(st.top() != 'E')
    {
        char c=st.top();
        st.pop();
        res+=c;
    }
    cout << res << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        infixtopostfix(s);
    }
    return 0;
}