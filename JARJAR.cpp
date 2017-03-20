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

const int me = 60025;

int N, Q;
int dp[65][me], w[65];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> N >> Q){
        if(N + Q == 0)
            break;
        for(int i = 1; i <= N; i ++)
            cin >> w[i];
        for(int i = 1; i < 65; i ++)
            for(int j = 1; j < me; j ++)
                dp[i][j] = 0;
        for(int i = 1; i <= N; i ++){
            for(int j = N; j > 1; j --){
                for(int k = me - 1 - w[i]; k > 0; k --)
                    if(dp[j - 1][k])
                        dp[j][k + w[i]] = 1;
            }
            dp[1][w[i]] = 1;
        }
        while(Q --){
            int X;
            int output = 0;
            cin >> X;
            for(int i = 1; i <= N && X < me && X > 0; i ++){
                if(dp[i][X] == 1){
                    if(output)
                        cout << " ";
                    cout << i;
                    output = 1;
                }
            }
            if(!output)
                cout << "That's impossible!";
            cout << endl;
        }
    }
    
    return 0;
}
