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

const int me = 1525;
const double eps = 1.e-15;

int n, ans;
long long x[me], y[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout << M_PI << endl;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < n; i ++){
        vector<double> v;
        for(int j = 0; j < n; j ++)
            if(i != j)
                v.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        for(auto &j : v)
            if(j < 0.)
                j += M_PI;
        //cout << i + 1 << ": " << endl;
        //for(int j = 0; j < n - 1; j ++)
        //    cout << v[j] << ", ";
        //cout << endl;
        
        sort(v.begin(), v.end());
        for(int j = 0; j < n - 1 && v[j] < M_PI / 2. + eps; j ++){
            ans += upper_bound(v.begin(), v.end(), v[j] + M_PI / 2 + eps)
            - lower_bound(v.begin(), v.end(), v[j] + M_PI / 2 - eps);
        }
    }
    cout << ans << endl;
    
    return 0;
}