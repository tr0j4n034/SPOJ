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

const int me = 125;

int T;
int N;
int f[me], p[300000];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    f[0] = 1;
    for(int i = 1; i < me; i ++)
        f[i] = f[i - 1] + (i > 3 ? f[i - 4] : 0);
    for(int i = 2; i < f[40] + 5; i ++)
        if(!p[i])
            for(int j = i + i; j < f[40] + 5; j += i)
                p[j] = 1;
    cin >> T;
    while(T --){
        cin >> N;
        int s = 0;
        for(int i = 2; i <= f[N]; i ++)
            s += 1 - p[i];
        cout << s << endl;
    }
    
    return 0;
}
