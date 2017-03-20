#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 10025;

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}
template<class T> static void uput(T n)
{
    char s[30];
    int x = 0;
    do { s[x ++]=(n % 10) + '0'; n /= 10; } while(n);
    for(int i = x - 1; i >= 0; i --) putchar(s[i]);
    putchar('\n');
}

int t, n;
int a[me];
long long dp[me][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n;
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        dp[0][0] = 0;
        dp[0][1] = a[0];
        for(int i = 1; i < n; i ++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0] + a[i], dp[i - 1][1]);
        }
        cout << "Case " << c + 1 << ": ";
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    
    return 0;
}