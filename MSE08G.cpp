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
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;
const long long INF = 1000000000000LL;

vector<long long> lucky, v;

void go(long long x){
    if(x > INF)
        return;
    if(x > 0)
        lucky.push_back(x);
    go(x * 10 + 4);
    go(x * 10 + 7);
}
void gen(long long x, int pos){
    if(pos >= (int)lucky.size())
        return;
    if(x > 1)
        v.push_back(x);
    for(int i = pos; i < (int)lucky.size(); i ++){
        if(x > INF / lucky[i])
            break;
        gen(x * lucky[i], i);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    go(0);
    sort(lucky.begin(), lucky.end());
    gen(1, 0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    int t;
    long long a, b;
    
    cin >> t;
    while(t --){
        cin >> a >> b;
        printf("%d\n", (int)distance(lower_bound(v.begin(), v.end(), a),
                             lower_bound(v.begin(), v.end(), b + 1)));
    }
    
    return 0;
}
