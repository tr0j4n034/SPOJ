#include<iostream>
#include <list>
#include <stack>
#include <vector>
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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;

int t, n;
int a[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    for(int c = 0; c < t; c ++){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int ptr = n - 1, ans = n;
        for(int i = n - 1; i >= 0; i --){
            if(a[ptr] >= 2 * a[i]){
                ans --;
                ptr --;
            }
        }
        cout << "Case " << c + 1 << ": " << ans << endl;
    }
    

    return 0;
}

