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

const int me = 100025;

int T;
long long N;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        if(N & 1){
            N = (N + 3) * (N + 3);
            int r = N % 48;
            N /= 48;
            if(r > 24)
                N ++;
        }
        else{
            N *= N;
            int r = N % 48;
            N /= 48;
            if(r > 24)
                N ++;
        }
        cout << N << endl;
    }
    
    
    return 0;
}
