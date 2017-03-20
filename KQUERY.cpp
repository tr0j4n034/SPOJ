#include <bits/stdc++.h>
 
using namespace std;
 
const int me = 200025;
 
struct data{
    int value;
    int pos;
    data() {}
    data(int value, int pos) : value(value), pos(pos) {}
    bool operator <(const data other) const{
        return value < other.value;
    }
    bool operator >(const data other) const{
        return value > other.value;
    }
};
struct query{
    int l;
    int r;
    int k;
    int pos;
    query() {}
    query(int l, int r, int k, int pos) : l(l), r(r), k(k), pos(pos) {}
    bool operator <(const query other) const{
        return k < other.k;
    }
    bool operator >(const query other) const{
        return k > other.k;
    }
};
 
data a[me];
query q[me];
int ft[me], ans[me];
int n, m;
 
void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
 
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
 
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &a[i].value);
        a[i].pos = i + 1;
    }
    sort(a, a + n, less<data>());
    scanf("%d", &m);
    for(int i = 0; i < m; i ++){
        scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
        q[i].pos = i;
    }
    sort(q, q + m, greater<query>());
    for(int i = 0; i < m; i ++){
        while(n > 0 && a[n - 1].value > q[i].k){
            add(a[n - 1].pos, 1);
            n --;
        }
        ans[ q[i].pos ] = get(q[i].r) - get(q[i].l - 1);
    }
    for(int i = 0; i < m; i ++)
        printf("%d\n", ans[i]);
 
    return 0;
}