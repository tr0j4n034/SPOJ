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

const int me = 1000025;
const int mod = 314159;

int T, N;
int a[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    a[0] = 1, a[1] = 9;
    for(int i = 2; i < me; i ++)
        a[i] = (18 * a[i - 1] - 80 * a[i - 2] + 100 * mod) % mod;
    cin >> T;
    while(T --){
        cin >> N;
        cout << a[N] << endl;
    }
    
    return 0;
}
