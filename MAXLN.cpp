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

const int me = 1000025;

double calc(double r, double angle){
    double ab = 2. * r * sin(angle);
    double ac = 2. * r * cos(angle);
    return ab * ab + ac;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    double r;
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> r;
        double low = 0., high = M_PI, mid1, mid2;
        for(int i = 0; i < 100; i ++){
            mid1 = (low + low + high) / 3.;
            mid2 = (low + high + high) / 3.;
            if(calc(r, mid1) > calc(r, mid2))
                high = mid2;
            else low = mid1;
        }
        cout << "Case " << c + 1 << ": ";
        cout.precision(2);
        cout << fixed << calc(r, low) << endl;
    }
    
    return 0;
}
