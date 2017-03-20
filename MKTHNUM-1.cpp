#include <bits/stdc++.h>
 
using namespace std;
 
const int me = 100025;
const int MAX_LOG = 20;
 
int n, q, l, r, k;
int a[me], v[me];
int st[MAX_LOG][me << 2];
 
void Merge(int I, int l1, int r1, int l2, int r2){
    int ptr = l1;
    while(l1 <= r1 && l2 <= r2)
        st[I][ptr ++] = st[I + 1][l1] < st[I + 1][l2] ? st[I + 1][l1 ++] : st[I + 1][l2 ++];
    while(l1 <= r1)
        st[I][ptr ++] = st[I + 1][l1 ++];
    while(l2 <= r2)
        st[I][ptr ++] = st[I + 1][l2 ++];
}
void build(int I, int low, int high){
    if(low > high)
        return;
    if(low == high){
        st[I][low] = a[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(I + 1, low, mid);
    build(I + 1, mid + 1, high);
    Merge(I, low, mid, mid + 1, high);
}
int query(int I, int low, int high, int l, int r, int k){
    if(low > high || low > r || high < l)
        return 0;
    if(low >= l && high <= r){
        return upper_bound(st[I] + low, st[I] + high + 1, k) - (st[I] + low);
    }
    int mid = (low + high) >> 1;
    return query(I + 1, low, mid, l, r, k)
            + query(I + 1, mid + 1, high, l, r, k);
}
int Kth_element(int l, int r, int k){
    int low = 1, high = n, mid, best = high;
    while(low <= high){
        mid = (low + high + 1) >> 1;//cout << "mid = " << mid << endl;
        int g = query(1, 1, n, l, r, mid);//cout << endl << "q-result: " << mid << " " << g << endl;
        if(g >= k){
            best = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return v[best];
}
void compress(){
    map<int, int> m, pos;
    for(int i = 1; i <= n; i ++)
        m[ a[i] ] = 1;
    int ptr = 1;
    for(auto i : m)
        pos[i.first] = ptr ++;
    for(int i = 1; i <= n; i ++){
        int value = a[i];
        a[i] = pos[ a[i] ];
        v[ a[i] ] = value;
    }
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
 
    a[0] = 0;
    a[1] = 1;
    a[2] = 2, a[3] = 3, a[4] = 5, a[5] = 6, a[6] = 10, a[7] = 15, a[8] = 18, a[9] = 20;
    l = 3, r = 8, k = 19;
    int x = upper_bound(a + l, a + r + 1, k) - (a + l);
    //cout << x << endl;
    //return 0;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    compress();//for(int i = 1; i <= n; i ++) cout << a[i] << ", "; cout << endl;
    build(1, 1, n);//for(int i = 1; i <= n; i ++) cout << st[3][i] << ", "; cout << endl;
    while(q --){
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", Kth_element(l, r, k));
    }
 
    return 0;
}