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
pnode add(pnode &root, int low, int high, int pos, int value){
    if(!root)
        root = Init(0);
    if(low == high){
        pnode p = Init(value);
        p->sum += root->sum;
        return p;
    }
    int mid = (low + high) >> 1;
    pnode p = Init(0);
    if(pos <= mid){
        p->l = add(root->l, low, mid, pos, value);
        p->r = root->r;
    }
    else{
        p->l = root->l;
        p->r = add(root->r, mid + 1, high, pos, value);
    }
    Gather(p);
    return p;
}
int GetKthElement(pnode &root, int low, int high, int k){
    if(low == high)
        return low;
    int mid = (low + high) >> 1;
    if(get(root->l) >= k)
        return GetKthElement(root->l, low, mid, k);
    else return GetKthElement(root->r, mid + 1, high, k - get(root->l));
}

pnode roots[me];
vector<int> pos[me];

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

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = inp(), q = inp();
    for(int i = 1; i <= n; i ++)
        a[i] = inp();
    
    vector<int> values(a + 1, a + n + 1);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    int N = (int)values.size();
    for(int i = 0; i < N; i ++){
        real[i + 1] = values[i];
    }
    for(int i = 1; i <= n; i ++)
        a[i] = (int)(lower_bound(values.begin(), values.end(), a[i]) - values.begin()) + 1;
    for(int i = 1; i <= n; i ++)
        pos[a[i]].push_back(i);
    roots[0] = Init(0);
    for(int i = 1; i <= n; i ++)
        roots[i] = add(roots[i - 1], 1, N, a[i], 1);
    while(q --){
        int k = inp(), f = inp(), l = inp();
        int d = GetKthElement(roots[f + 1], 1, N, k);
        if((int)pos[d].size() < l)
            printf("-1\n");
        else printf("%d\n", pos[d][l - 1] - 1);
    }
    
    return 0;
}
