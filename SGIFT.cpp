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

const int me = 100025;

int N, Q, L, R;
long long prefix[me];
vector<int> values;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    values.resize(N);
    for(int i = 0; i < N; i ++)
        cin >> values[i];
    sort(values.begin(), values.end());
    for(int i = 0; i < N; i ++){
        if(i == 0)
            prefix[i] = values[i];
        else prefix[i] = prefix[i - 1] + values[i];
    }
    cin >> Q;
    while(Q --){
        cin >> L >> R;
        if(L > R)
            swap(L, R);
        int p1 = (int)(--upper_bound(values.begin(), values.end(), L - 1) - values.begin());
        int p2 = (int)(--upper_bound(values.begin(), values.end(), R) - values.begin());
        cout << prefix[p2] - (p1 == -1 ? 0 : prefix[p1]) << endl;
    }
    
    return 0;
}
