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

const int me = 100025;

int N, Q;
int a[me], b[me], l[me], r[me];
int st[me << 3], lazy[me << 2];

void push(int I, int low, int high){
    if(lazy[I] != 0){
        st[I] += lazy[I];
        if(low != high){
            lazy[I << 1] += lazy[I];
            lazy[I << 1 | 1] += lazy[I];
        }
        lazy[I] = 0;
    }
}
void update(int I, int low, int high, int l, int r, int value){
    push(I, low, high);
    if(low > r || high < l)
        return;
    if(low >= l && high <= r){
        lazy[I] += value;
        push(I, low, high);
        return;
    }
    int mid = (low + high) >> 1;
    update(I << 1, low, mid, l, r, value);
    update(I << 1 | 1, mid + 1, high, l, r, value);
    st[I] = max(st[I << 1], st[I << 1 | 1]);
}
int get(int I, int low, int high, int l, int r){
    push(I, low, high);
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return max(get(I << 1, low, mid, l, r),
               get(I << 1 | 1, mid + 1, high, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i ++)
        cin >> a[i] >> b[i];
    cin >> Q;
    for(int i = 1; i <= Q; i ++)
        cin >> l[i] >> r[i];
    
    vector<int> values;
    for(int i = 1; i <= N; i ++){
        values.push_back(a[i]);
        values.push_back(b[i]);
    }
    for(int i = 1; i <= Q; i ++){
        values.push_back(l[i]);
        values.push_back(r[i]);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    
    for(int i = 1; i <= N; i ++){
        a[i] = (int)(lower_bound(values.begin(), values.end(), a[i]) - values.begin()) + 1;
        b[i] = (int)(lower_bound(values.begin(), values.end(), b[i]) - values.begin()) + 1;
    }
    for(int i = 1; i <= Q; i ++){
        l[i] = (int)(lower_bound(values.begin(), values.end(), l[i]) - values.begin()) + 1;
        r[i] = (int)(lower_bound(values.begin(), values.end(), r[i]) - values.begin()) + 1;
    }
    
    int SZ = (int)values.size();
    for(int i = 1; i <= N; i ++)
        update(1, 1, SZ, a[i], b[i], 1);
    for(int i = 1; i <= Q; i ++)
        cout << get(1, 1, SZ, l[i], r[i]) << endl;
    
    return 0;
}
