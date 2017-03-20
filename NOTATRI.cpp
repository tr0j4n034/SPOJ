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

const int me = 2025;

int n;
int a[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    while(scanf("%d", &n)){
        if(n == 0)
            break;
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int s = 0;
        for(int i = 0; i < n; i ++){
            int ptr = i;
            for(int j = i + 1; j < n; j ++){
                while(ptr < n && a[i] + a[j] >= a[ptr])
                    ptr ++;
                s += n - ptr;
            }
        }
        printf("%d\n", s);
    }
    
    return 0;
}