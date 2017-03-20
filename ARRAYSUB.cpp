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
#include <set>
#include <map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1000025;

int n, k;
int a[me];
multiset<int> s;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for(int i = 1; i < k; i ++)
        s.insert(a[i]);
    for(int i = k; i <= n; i ++){
        if(i > k)
            s.erase(s.find(a[i - k]));
        s.insert(a[i]);
        printf("%d", *(--s.end()));
        if(i < n)
            putchar(' ');
        }
    putchar('\n');
    
    return 0;
}