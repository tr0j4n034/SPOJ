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

const int me = 5000025;

unsigned a, b, m, k;
unsigned arr[me];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> m >> k;
    for( int i = 0 ; i < 5000000 ; i ++)
    {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        arr[i] = ((a << 16) + b) % m;
    }
    nth_element(arr, arr + k - 1, arr + 5000000);
    cout << arr[k - 1] << endl;
    
    return 0;
}