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

int n, q;
int a[me], real[me];

struct node{
    int sum;
    node *l, *r;
    node() {}
};
typedef node* pnode;

int get(pnode &root){
    return root ? root->sum : 0;
}
pnode Init(int value){
    pnode p = (pnode)malloc(sizeof(node));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void Gather(pnode &root){
    if(root)
        root->sum = get(root->l) + get(root->r);
}
void update(pnode &root, int low, int high, int pos, int value){
    if(!root)
        root = Init(0);
    if(low == high){
        root->sum += value;
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(root->l, low, mid, pos, value);
    else update(root->r, mid + 1, high, pos, value);
    Gather(root);
}
int get(pnode &root, int low, int high, int l, int r){
    if(!root)
        return 0;
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return root->sum;
    int mid = (low + high) >> 1;
    return get(root->l, low, mid, l, r) + get(root->r, mid + 1, high, l, r);
}

pnode roots[me];
int active[me];

inline int inp()
{
    int n = 0;
    int ch = getchar();
    int sign = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            sign = -1;
        ch=getchar();
    }
    while(ch >= '0' && ch <= '9')
        n = (n << 3) + ( n << 1) + ch - '0', ch = getchar();
    return n * sign;
}
template<class T> static void uput(T n)
{
    if(n < 0){
        putchar('-');
        n *= -1;
    }
    char s[30];
    int x = 0;
    do { s[x ++]=(n % 10) + '0'; n /= 10; } while(n);
    for(int i = x - 1; i >= 0; i --) putchar(s[i]);
    putchar('\n');
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = inp(), q = inp();
    for(int i = 1; i <= n; i ++)
        a[i] = inp();
    fill(active + 1, active + n + 1, 1);
    vector<int> values(a + 1, a + n + 1);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for(int i = 1; i <= n; i ++){
        a[i] = (int)(lower_bound(values.begin(), values.end(), a[i]) - values.begin()) + 1;
        update(roots[a[i]], 1, n, i, 1);
    }
    set<int> s(values.begin(), values.end());
    
    while(q --){
        int type = inp();
        if(type == 0){
            int l = inp() + 1, r = inp() + 1, k = inp();
            if(s.find(k) == s.end())
                printf("0\n");
            else{
                int d = (int)(lower_bound(values.begin(), values.end(), k) - values.begin()) + 1;
                uput(get(roots[d], 1, n, l, r));
            }
        }
        else{
            int k = inp() + 1;
            update(roots[a[k]], 1, n, k, -active[k]);
            active[k] *= -1;
        }
    }
    
    return 0;
}
