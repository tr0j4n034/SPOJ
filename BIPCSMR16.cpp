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
long long v[3];

long long solve(){
    sort(v, v + 3);
    if((v[0] + v[1]) * 2 <= v[2])
        return v[0] + v[1];
    long long sum = v[0] + v[1] + v[2];
    return sum / 3;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> v[0] >> v[1] >> v[2];
        cout << solve() << endl;
    }
   
    
    return 0;
}
