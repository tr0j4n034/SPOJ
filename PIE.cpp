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

const int me = 10025;

int t, n, f;
double a[me];
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d%d", &n, &f);
        ++f;
        for(int i = 0; i < n; i ++)
            scanf("%lf", &a[i]);
        double low = 0., high = 123456, mid;
        for(int i = 0; i < 100; i ++){
            mid = (low + high) / 2.;
            int cnt = 0;
            for(int j = 0; j < n && cnt < f; j ++)
                cnt += (int)(a[j] * a[j] / mid / mid);
            if(cnt >= f){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        printf("%.4lf\n", low * low * M_PI);
    }
    
    
    return 0;
}