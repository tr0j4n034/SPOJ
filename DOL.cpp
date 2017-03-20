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
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1025;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    long long n;
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n;
        while(n % 2 == 0)
            n /= 2;
        cout << "Case " << c + 1 << ": " << n << endl;
    }
    
    return 0;
}
