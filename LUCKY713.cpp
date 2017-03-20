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

const int me = 10025;

int T, N;

long long get(int low, int high, int d){
    int n = (high - low) / d + 1;
    return 1LL * (low + high) * n / 2;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> T;
    
    for(int c = 0; c < T; c ++){
        cin >> N;
        cout << "Case " << c + 1 << ": ";
        cout << get(0, N / 7 * 7, 7) + get(0, N / 13 * 13, 13) - get(0, N / 91 * 91, 91) -
        ((N % 7 == 0 || N % 13 == 0) ? N : 0) << endl;
    }
    
    return 0;
}
