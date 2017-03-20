#include <bits/stdc++.h>
 
using namespace std;
 
const int me = 200025;
 
int t, n;
int l[me], r[me], lazy[me << 2], st[me << 2];
int where[me * 60];
 
void push(int node){
    if(lazy[node]){
        st[node] = lazy[node];
        lazy[node << 1] = lazy[node];
        lazy[(node << 1) | 1] = lazy[node];
        lazy[node] = 0;
    }
}
void update(int I, int low, int high, int l, int r, int value){
    push(I);
    if(low > high || low > r || high < l)
        return;
    if(low >= l && high <= r){
        lazy[I] = value;
        push(I);
        return;
    }
    int mid = (low + high) >> 1;
    update(I << 1, low, mid, l, r, value);
    update((I << 1) | 1, mid + 1, high, l, r, value);
}
int get(int I, int low, int high, int pos){
    if(low > pos || high < pos)
        return 0;
    push(I);
    if(low == high && low == pos)
        return st[I];
    int mid = (low + high) >> 1;
    if(pos <= mid)
        return get(I << 1, low, mid, pos);
    return get((I << 1) | 1, mid + 1, high, pos);
}
 
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
 
    scanf("%d", &t);
    for(int c = 0; c < t; c ++){
        scanf("%d", &n);
        map<int, int> pos;
        for(int i = 0; i < (me << 2); i ++){
            st[i] = 0;
            lazy[i] = 0;
        }
        for(int i = 0; i < n; i ++){
            scanf("%d%d", &l[i], &r[i]);
            pos[ l[i] ] = 1;
            pos[ r[i] ] = 1;
        }
        int cnt = 0;
        for(auto i : pos)
            where[i.first] = ++cnt;
        for(int i = 0; i < n; i ++)
            update(1, 1, cnt, where[ l[i] ], where[ r[i] ], i + 1);
        set<int> s;
        for(auto i : pos){
            int g = get(1, 1, cnt, where[i.first]);
            s.insert(g);
        }
        printf("%d\n", s.size());
    }
    return 0;
}