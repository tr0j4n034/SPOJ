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

const int me = 100025;

int a, b, n, ans;
vector<int> d[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> n;
    if(a > b)
        swap(a, b);
    for(int i = 2; i * i <= b; i ++)
        for(int j = (a % i == 0 ? a : a - a % i + i); j <= b; j += i)
            d[j - a].push_back(i);
    for(int i = a; i <= b; i ++){
        int t = i;
        int cnt = 1;
        for(int j : d[i - a]){
            if(t < 2)
                break;
            int l = 0;
            while(t % j == 0){
                l ++;
                t /= j;
            }
            cnt *= l + 1;
        }
        if(t > 1)
            cnt *= 2;
        if(cnt == n)
            ans ++;
    }
    cout << ans << endl;
    
    return 0;
}
