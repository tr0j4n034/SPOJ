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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bitset>

using namespace std;

const int me = 2025;

int T;
long long N;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> T;
    while(T --){
        cin >> N;
        long long low = 0, high = 1 << 18, mid, best = high;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            if(mid * (mid + 1) / 2 >= N){
                best = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(best * (best + 1) / 2 == N)
            cout << best << endl;
        else cout << "NAI" << endl;
    }

    return 0;
}
