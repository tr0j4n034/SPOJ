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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1025;

int n;
int dp[me][2];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> s){
        s = "$" + s;
        n = (int)s.size();
        for(int i = 1; i < n; i ++){
            if(isupper(s[i])){
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][0];
            }
            else{
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = dp[i - 1][1];
            }
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    
    
    return 0;
}