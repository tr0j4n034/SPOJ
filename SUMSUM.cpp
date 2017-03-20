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
const int sz = 29;

int N, Q;
int f, l, r, v;
string type;
int a[me], ft[sz][me];

void add(int *ft, int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int *ft, int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
int get(int *ft, int l, int r){
    return get(ft, r) - get(ft, l - 1);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> Q;
    for(int i = 1; i <= N; i ++)
        cin >> a[i];
    for(int i = 0; i < sz; i ++)
        for(int j = 1; j <= N; j ++)
            if(a[j] & (1 << i)){
                add(ft[i], j, 1);
            }
    while(Q --){
        cin >> f;
        if(f == 1){
            cin >> v >> l;
            for(int i = 0; i < sz; i ++)
                if(a[l] & (1 << i))
                    add(ft[i], l, -1);
            a[l] = v;
            for(int i = 0; i < sz; i ++)
                if(a[l] & (1 << i))
                    add(ft[i], l, 1);
        }
        else{
            cin >> type >> l >> r;
            long long result = 0;
            for(int i = 0; i < sz; i ++){
                int ones = get(ft[i], l, r);
                int zeroes = r - l + 1 - ones;
                if(type == "XOR"){
                    result += 1LL * (1 << i) * ones * zeroes;
                }
                else if(type == "OR"){
                    result += 1LL * (1 << i) * ones * zeroes + 1LL * (1 << i) * ones * (ones - 1) / 2;
                }
                else{
                    result += 1LL * (1 << i) * ones * (ones - 1) / 2;
                }
            }
            cout << result << endl;
        }
    }
    
    return 0;
}
