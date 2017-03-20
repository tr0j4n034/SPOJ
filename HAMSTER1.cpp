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

int t;
double v0, k1, k2;

double get(double angle){
    return k2 * v0 * v0 * sin(angle) * sin(angle) / 20. + k1 * v0 * v0 * sin(2 * angle) / 10.;
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> v0 >> k1 >> k2;
        double low = 0., high = M_PI / 2., mid1, mid2;
        for(int i = 0; i < 100; i ++){
            mid1 = (low + low + high) / 3.;
            mid2 = (low + high + high) / 3.;
            if(get(mid1) > get(mid2)){
                high = mid2;
            }
            else{
                low = mid1;
            }
        }
        printf("%.3lf %.3lf\n", low, get(low));
    }
    
    return 0;
}