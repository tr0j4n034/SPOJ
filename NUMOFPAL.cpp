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

const int me = 1025;

int N;
string s;
int pal[me][me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    N = (int)s.size();
    s = "$" + s;
    
    for(int i = 1; i <= N; i ++)
        pal[i][i] = 1;
    for(int i = 1; i < N; i ++)
        pal[i][i + 1] = (s[i] == s[i + 1]);
    for(int d = 2; d < N; d ++)
        for(int i = 1; i + d <= N; i ++)
            pal[i][i + d] = pal[i + 1][i + d - 1] && s[i] == s[i + d];
    int result = 0;
    for(int d = 1; d <= N; d ++)
        for(int j = 1; j + d - 1 <= N; j ++)
            if(pal[j][j + d - 1])
                result ++;
    cout << result << endl;
    
    return 0;
}
