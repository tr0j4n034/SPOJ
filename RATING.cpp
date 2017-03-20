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

const int me = 300025;

int n;
int ft[me], ans[me];
pair<pair<int, int>, int> a[me];
vector<int> values;

void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = uget();
    for(int i = 0; i < n; i ++){
        a[i].first.first = uget();
        a[i].first.second = uget();
        a[i].second = i;
        values.push_back(a[i].first.second);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for(int i = 0; i < n; i ++){
        a[i].first.second = (int)(lower_bound(values.begin(), values.end(), a[i].first.second) - values.begin()) + 1;
    }
    sort(a, a + n);
    for(int i = 0; i < n; ){
        ans[a[i].second] = get(a[i].first.second);
        add(a[i].first.second, 1);
        int j = i + 1;
        while(j < n && a[i].first == a[j].first){
            ans[a[j].second] = ans[a[i].second];
            add(a[j].first.second, 1);
            ++ j;
        }
        i = j;
    }
    for(int i = 0; i < n; i ++)
        uput(ans[i]);
    
    return 0;
}
