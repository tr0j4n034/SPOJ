#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define y1 lalalalalala
#define index lalalalalalala
#define show(a, i) cout << "a[" << i << "] = " << a[i] << endl;
#define all(x) x.begin(), x.end()
#define FAST_INPUT
#define LLOCAL
#define CC++

typedef long long ll;
typedef pair<int, int>pii;
typedef pair<int, pair<int, int> >ppii;

const int MAX = 1.e5;
const int INF = 1.e9 + 1;
const double eps = 1.e-9;
const double PI = 3.14159265358979311599796;

#ifdef FAST_INPUT

int getint()
{
    char ch;
    int neg = 1;
    int val = 0;
    
    while(ch = getchar())
    {
        if(ch == '-')   neg = -1;
        else if(ch > 57 || ch < 48)  break;
        else val = 10 * val + ch - 48;
    }
    val = val * neg;
    return val;
}

#endif // FAST_INPUT
/// 4492

const int cs = 100001;
const int M = cs - 1;

int a[cs], c[cs << 1], start[cs << 1], st[cs << 3];
int n, q, l, r;

int build(int I, int low, int high)
{
    if(low > high)
        return 0;
    
    if(low == high)
    {
        st[I] = c[ a[low] ];
        return st[I];
    }
    
    int mid = (low + high) >> 1;
    
    int q1 = build(I + I, low, mid);
    int q2 = build(I + I + 1, mid + 1, high);
    
    return st[I] = max(q1, q2);
}

int get(int I, int low, int high, int l, int r)
{
    if(low > high || low > r || high < l)
        return 0;
    
    if(low >= l && high <= r)
    {
        return st[I];
    }
    
    int mid = (low + high) >> 1;
    
    int q1 = get(I + I, low, mid, l, r);
    int q2 = get(I + I + 1, mid + 1, high, l, r);
    
    return max(q1, q2);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    
#define C++
#ifndef C
    ios_base::sync_with_stdio(false);
    cin.tie(false);
#endif // C
    
    while(cin >> n)
    {
        if(n == 0)
            return 0;
        cin >> q;
        for(int i = 2 * cs - 1 ; i >= 0 ; i --)
        {
            c[i] = 0;
            start[i] = 0;
        }
        for(int i = 1 ; i <= n ; i ++)
        {
            cin >> a[i];
            a[i] += M;
            if(!c[ a[i] ])
                start[ a[i] ] = i;
            c[ a[i] ] ++;
        }
        
        build(1, 1, n);
        
        while(q --)
        {
            cin >> l >> r;
            
            if(a[l] == a[r])
            {
                cout << r - l + 1 << endl;
                continue;
            }
            
            int q1 = c[ a[l] ] + start[ a[l] ] - l;
            int q2 = r - start[ a[r] ] + 1;
            int q3 = get(1, 1, n, start[ a[l] ] + c[ a[l] ], start[ a[r] ] - 1);
            
            cout << max(q1, max(q2, q3)) << endl;
        }
    }
    
    ///cerr << "Elapsed time: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
