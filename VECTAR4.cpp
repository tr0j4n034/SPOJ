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

const int me = 1000025;

int T;
long long N;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        long long low = 1, high = 1LL << 32, mid, best = high;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            long long s;
            if(mid & 1){
                s = (mid / 2 + 1)+ (mid / 2) * (mid / 2 + 1);
            }
            else{
                s = (mid / 2) * (mid / 2 + 1);
            }
            if(s >= N){
                best = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << best << endl;
    }
    
    return 0;
}
