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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 1025;

int N, U, Q;
int l, r;
pair<int, int> updates[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> U >> Q;
    for(int i = 0; i < U; i ++)
        cin >> updates[i].first >> updates[i].second;
    for(int i = 0; i < Q; i ++){
        cin >> l >> r;
        long long result = 0;
        for(auto j : updates){
            if(j.first > r || j.second < l)
                continue;
            long long from = max(j.first, l);
            long long to = min(j.second, r);
            from -= j.first - 1;
            to -= j.first - 1;
            long long add = to * (to + 1) / 2 - from * (from - 1) / 2;
            result = (result + add) % 10000;
        }
        cout << result << endl;
    }

    return 0;
}
