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
const int mod = 1000000007;

int T, N, M;
/*
 1 32
 2 16
 4 8
 */
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> T;
    
    for(int c = 0; c < T; c ++){
        cin >> N >> M;
        
        int result = 1;
        for(int i = 1; i <= M; i ++){
            result = 1LL * result * N % mod;
        }
        long long s = 0;
        for(int i = 1; i * i <= result; i ++){
            if(result % i == 0){
                s += i;
                if(i * i != result)
                    s += result / i;
            }
        }
        cout << "Case " << c + 1 << ": " << s << endl;
    }
    
    return 0;
}
