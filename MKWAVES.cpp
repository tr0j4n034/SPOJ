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
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 10025;
const double pi = acos(-1.);
const double epsilon = 1.e-5;

int N;
int cases = 0;
double f[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> N){
        if(N == 0)
            break;
        ++cases;
        for(int i = 1; i <= N; i ++)
            cin >> f[i];
        int a = -1, b = -1;
        for(int i = 400; i <= 600 && a == -1; i ++)
            for(int j = 400; j <= 600 && a == -1; j ++){
                bool ok = true;
                for(int k = 1; k <= N && ok; k ++){
                    double ff = sin(1. * i * k * pi / 180. / N) + sin(1. * j * k * pi / 180. / N);
                    if(fabs(f[k] - ff) > epsilon)
                       ok = false;
                }
                if(ok){
                    a = i, b = j;
                }
            }
        cout << "Case " << cases << ", f1 = " << a << ", f2 = " << b << endl;
    }
    
    return 0;
}
