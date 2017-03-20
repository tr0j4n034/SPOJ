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
    
    int c[30][30];
    for(int i = 0; i < 30; i ++)
        for(int j = 0; j <= i; j ++){
            if(j == 0)
                c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    
    int t, n, m;
    cin >> t;
    while(t --){
        cin >> n >> m;
        cout << c[n + m - 2][n - 1] << endl;
    }
    
    return 0;
}
