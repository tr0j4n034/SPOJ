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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1000025;


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    int n;
    
    while(scanf("%d", &n) != EOF){
        int ans = 0;
        while(n > 0){
            char s[10];
            fill(s, s + 10, '0');
            sprintf(s, "%d", n);
            sort(s, s + (int)strlen(s));
            n -= atoi(s);
            ans ++;
        }
        cout << ans << endl;
    }
    
    return 0;
}
