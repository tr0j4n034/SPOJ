    #include <bits/stdc++.h>
    #define MAXN 100100
     
    using namespace std;
     
    struct Node {
        int ans;
        int cnt_0, cnt_1;
    } V[4*MAXN][2]; // 0 - original, 1 - toggled
     
    int n,m;
    int in[MAXN];
    int T[4*MAXN];
     
    void build(int l, int r, int v) {
        if(l == r) {
            V[v][0].ans = 1;
            if(in[l] == 0) {
                V[v][0].cnt_0 = 1;
                V[v][0].cnt_1 = 0;
            } else {
                V[v][0].cnt_0 = 0;
                V[v][0].cnt_1 = 1;
            }
            V[v][1].ans = 1;
            V[v][1].cnt_0 = 1 - V[v][0].cnt_0;
            V[v][1].cnt_1 = 1 - V[v][0].cnt_1;
            return;
        }
     
        int mid = (l+r)>>1;
        build(l,mid, 2*v);
        build(mid+1, r, 2*v+1);
        V[v][0].cnt_0 = V[v*2][0].cnt_0 + V[v*2+1][0].cnt_0;
        V[v][0].cnt_1 = V[v*2][0].cnt_1 + V[v*2+1][0].cnt_1;
        V[v][1].cnt_0 = V[v*2][1].cnt_0 + V[v*2+1][1].cnt_0;
        V[v][1].cnt_1 = V[v*2][1].cnt_1 + V[v*2+1][1].cnt_1;
     
        V[v][0].ans = max(V[v*2][0].ans + V[v*2+1][0].cnt_1, V[v*2][0].cnt_0 + V[v*2+1][0].ans);
        V[v][1].ans = max(V[v*2][1].ans + V[v*2+1][1].cnt_1, V[v*2][1].cnt_0 + V[v*2+1][1].ans);
    }
     
    void toggle(int l, int r, int v, int lll, int rrr) {
        if(lll <= l && rrr >= r) {
            swap(V[v][0], V[v][1]);
            T[v] = 1 - T[v];
            return;
        }
     
        int mid = (l+r)>>1;
        if(T[v] == 1) {
            swap(V[v*2][0], V[v*2][1]);
            T[v*2] = 1 - T[v*2];
            swap(V[v*2+1][0], V[v*2+1][1]);
            T[v*2+1] = 1 - T[v*2+1];
            T[v] = 0;
        }
     
        if(lll <= mid)
            toggle(l, mid, 2*v, lll, rrr);
        if(rrr > mid)
            toggle(mid+1, r, 2*v+1, lll, rrr);
     
        V[v][0].cnt_0 = V[v*2][0].cnt_0 + V[v*2+1][0].cnt_0;
        V[v][0].cnt_1 = V[v*2][0].cnt_1 + V[v*2+1][0].cnt_1;
        V[v][1].cnt_0 = V[v*2][1].cnt_0 + V[v*2+1][1].cnt_0;
        V[v][1].cnt_1 = V[v*2][1].cnt_1 + V[v*2+1][1].cnt_1;
        V[v][0].ans = max(V[v*2][0].ans + V[v*2+1][0].cnt_1, V[v*2][0].cnt_0 + V[v*2+1][0].ans);
        V[v][1].ans = max(V[v*2][1].ans + V[v*2+1][1].cnt_1, V[v*2][1].cnt_0 + V[v*2+1][1].ans);
    }
     
     
    int main() {
        cin>>n>>m;
        char ch;
        for(int i = 1; i <= n; ++i) {
            cin>>ch;
            if(ch == '0')
                in[i] = 0;
            else
                in[i] = 1;
        }
     
        build(1, n, 1);
     
        int type, l, r;
        for(int i = 0; i < m; ++i) {
            cin>>type;
            if(type == 1) {
                cout<<V[1][0].ans<<endl;
            } else {
                cin>>l>>r;
                toggle(1, n, 1, l, r);
            }
        }
     
        return 0;
    } 
