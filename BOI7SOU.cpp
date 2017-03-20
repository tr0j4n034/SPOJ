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
#include <unordered_map>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1000025;

int n, m, c, x;
int a[me];
vector<int> v;
multiset<int> s;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d%d", &n, &m, &c);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++){
        s.insert(a[i]);
        if(i > m)
            s.erase(s.find(a[i - m]));
        if(i >= m)
            if(*(--s.end()) - (*s.begin()) <= c)
                v.push_back(i - m + 1);
    }
    if(v.empty())
        printf("NONE\n");
    else{
        for(int i : v)
            printf("%d\n", i);
    }
    
    return 0;
}
