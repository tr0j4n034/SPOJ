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

const int me = 300025;

int t, n;
double a[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            scanf("%lf", &a[i]);
        }
        sort(a, a + n);
        int ok = 0;
        int ptr1 = 0, ptr2 = n - 1;
        for(int i = 0; i < n; i ++){
            while(ptr1 <= i && a[i] + a[ptr1] <= 1.)
                ptr1 ++;
            while(ptr2 > i + 1 && a[i] + a[ptr2] >= 2.)
                ptr2 --;
            if(ptr1 <= ptr2 && a[i] + a[ptr1] > 1. && a[i] + a[ptr2] < 2.){
                ok = 1;
                break;
            }
        }
        if(ok)
            puts("found");
        else puts("not found");
    }
    
    return 0;
}
