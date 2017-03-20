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

const int me = 40025;
const int offset = 20000;

int N;
int k, c;
bitset<me> bs[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    bs[0][offset] = 1;
    
    cin >> N;
    for(int i = 1; i <= N; i ++){
        cin >> k >> c;
        for(int j = 0; j + j <= k; j ++){
            int d = (k - j - j) * c;
            bs[i] |= (bs[i - 1] << d);
            bs[i] |= (bs[i - 1] >> d);
        }
    }
    int result = me;
    for(int i = 0; i < me; i ++)
        if(bs[N][i] == 1){
            result = min(result, abs(i - offset));
        }
    cout << result << endl;
    
    return 0;
}
