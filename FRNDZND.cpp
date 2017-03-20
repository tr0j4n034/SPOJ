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

const int me = 100025;

int n, q, l, r;
int a[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    while(q --){
        scanf("%d%d", &l, &r);
        if(l == r){
            printf("%d\n", a[l]);
        }
        else{
            printf("0\n");
        }
        continue;
        
        int ans = 0;
        int m = r - l + 1;
        for(int i = 0; i < (1 << m); i ++){
            int now = 0;
            for(int j = 0; j < m; j ++){
                if(i & (1 << j))
                    now ^= a[l + j];
            }
            ans ^= now;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
