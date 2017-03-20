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

const int me = 100000025;

char d[me];
int s[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    for(int i = 1; i < me; i ++){
        d[i] = d[i / 10];
        if((i % 10) & 1)
            d[i] -= i % 10;
        else d[i] += i % 10;
        s[i] = s[i - 1] + (d[i] > 0);
    }
    
    int t, a, b;
    
    cin >> t;
    while(t --){
        cin >> a >> b;
        cout << s[b] - s[a - 1] << endl;
    }
    
    return 0;
}
