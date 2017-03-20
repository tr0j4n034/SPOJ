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

const int me = 300025;

int Q, N;
int x[me], y[me], st[me << 2];
char type[me], name[me][25];
vector<pair<int, int>> compressor;
map<string, pair<int, int> > values;
map<string, int> poss;

void Update(int I, int low, int high, int pos, int value){
    if(low == high){
        st[I] = value;
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        Update(I << 1, low, mid, pos, value);
    else Update(I << 1 | 1, mid + 1, high, pos, value);
    st[I] = max(st[I << 1], st[I << 1 | 1]);
}
int Get(int I, int low, int high, int l, int r){
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return max(Get(I << 1, low, mid, l, r),
               Get(I << 1 | 1, mid + 1, high, l, r));
}
int GetLeft(int low, int high){
    int best = 0;
    while(low <= high){
        int mid = (low + high + 1) >> 1;
        int ask = Get(1, 1, N, mid, high);
        if(ask > 0){
            best = ask;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return best;
}
int GetRight(int low, int high){
    int best = 0;
    while(low <= high){
        int mid = (low + high + 1) >> 1;
        int ask = Get(1, 1, N, low, mid);
        if(ask > 0){
            best = ask;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return best;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &Q);
    for(int i = 0; i < Q; i ++){
        scanf(" %c%s", &type[i], name[i]);
        if(type[i] == 'A'){
            scanf("%d%d", &x[i], &y[i]);
            values[name[i]] = make_pair(x[i], y[i]);
            compressor.push_back(make_pair(x[i], y[i]));
        }
    }
    sort(compressor.begin(), compressor.end());
    N = (int)compressor.size();
    
    for(auto i : values){
        poss[i.first] = (int)(lower_bound(compressor.begin(), compressor.end(), i.second) - compressor.begin()) + 1;
    }
    
    long long result = 0;
    for(int i = 0; i < Q; i ++){
        if(type[i] == 'A'){
            int where = poss[name[i]];
            int l = GetLeft(1, where - 1);
            int r = GetRight(where + 1, N);
            result -= 1LL * l * r;
            result += 1LL * (l + r) * y[i];
            Update(1, 1, N, where, y[i]);
        }
        else{
            int where = poss[name[i]];
            int l = GetLeft(1, where - 1);
            int r = GetRight(where + 1, N);
            result += 1LL * l * r;
            result -= 1LL * (l + r) * values[name[i]].second;
            Update(1, 1, N, where, 0);
        }
        printf("%lld\n", result);
    }
        
    return 0;
}
