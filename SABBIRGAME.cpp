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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 1000025;

int T, N;
int a[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        for(int i = 0; i < N; i ++)
            cin >> a[i];
        long long result = 1, sum = 0;
        for(int i = 0; i < N; i ++){
            sum = sum + a[i];
            result = min(result, sum);
        }
        if(result > 0)
            cout << 0 << endl;
        else cout << -result + 1 << endl;
    }
    
    return 0;
}
