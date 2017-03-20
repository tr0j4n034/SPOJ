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

const int me = 2025;

int T, N;
string s;
int sum[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> s;
        N = (int)s.size();
        for(int i = 1; i <= N; i ++)
            sum[i] = sum[i - 1] + (s[i - 1] == 'K');
        int result = 0;
        for(int i = 1; i <= N; i ++)
            if(s[i - 1] == 'E')
                result += sum[i - 1] * (sum[N] - sum[i]);
        cout << result << endl;
    }
    
    return 0;
}
