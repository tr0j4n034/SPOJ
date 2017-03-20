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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;

typedef pair<int, int> pii;

int t, k, n;
string str;
pair<int, int> st[me * 5];

pii merge(pii a, pii b){
    if(a.first > b.first || (a.first == b.first && a.second < b.second))
        return a;
    return b;
}
void build(int I, int low, int high){
    if(low == high){
        st[I] = make_pair(k, low);
        return;
    }
    int mid = (low + high) >> 1;
    build(I + I, low, mid);
    build(I + I + 1, mid + 1, high);
    st[I] = make_pair(k, low);
}
void update(int I, int low, int high, int pos, int value){
    if(low == high){
        st[I].first += value;
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(I + I, low, mid, pos, value);
    else update(I + I + 1, mid + 1, high, pos, value);
    st[I] = merge(st[I + I], st[I + I + 1]);
}
pii get(int I, int low, int high, int pos){
    if(low == high)
        return st[I];
    int mid = (low + high) >> 1;
    if(pos <= mid)
        return get(I + I, low, mid, pos);
    else return get(I + I + 1, mid + 1, high, pos);
}
int get_index(int I, int low, int high, int value){
    if(low == high)
        return low;
    int mid = (low + high) >> 1;
    if(st[I + I].first >= value)
        return get_index(I + I, low, mid, value);
    else return get_index(I + I + 1, mid + 1, high, value);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &k);
        build(1, 1, me - 1);
        set<int> used;
        scanf("%d", &n);
        getchar();
        while(n > 0){
            int cnt = 0, v = 0;
            //gets(str);
            getline(cin, str);
            if(str[0] == 'b'){
                int ptr = 2;
                for( ; str[ptr] != ' '; ptr ++)
                    cnt = cnt * 10 + str[ptr] - '0';
                for( ++ptr; ptr < (int)str.size(); ptr ++)
                    v = v * 10 + str[ptr] - '0';
            }
            else{
                cnt = 1;
                for(int ptr = 0; ptr < (int)str.size(); ptr ++)
                    v = v * 10 + str[ptr] - '0';
            }
            n -= cnt;
            for(int i = 0; i < cnt; i ++){
                int pos = get_index(1, 1, me - 1, v);
                used.insert(pos);
                update(1, 1, me - 1, pos, -v);
            }
        }
        long long wasted = 0;
        for(int i : used)
            wasted += get(1, 1, me - 1, i).first;
        printf("%d %lld\n", (int)used.size(), wasted);
    }
    
    return 0;
}