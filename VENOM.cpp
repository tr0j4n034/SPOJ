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

const int me = 1025;

int T, H, P, A;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    while(T --){
        scanf("%d%d%d", &H, &P, &A);
        int low = 0, high = 1 << 28, mid, best = 0;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            long long now;
            if(mid & 1){
                now = H - 1LL * (mid / 2 + 1) * (mid / 2 + 2) / 2 * P + 1LL * mid / 2 * A;
            }
            else{
                now = H - 1LL * (mid / 2) * (mid / 2 + 1) / 2 * P + 1LL * mid / 2 * A;
            }
            if((mid % 2 == 1 && now > 0) || (mid % 2 == 0 && now > A)){
                best = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        printf("%d\n", best + 1);
    }
    
    return 0;
}
