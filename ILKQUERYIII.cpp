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
 
const int me = 1000025;
 
struct node{
    int sum;
    node *l, *r;
    
    node(){
        
    }
};
 
typedef node* pnode;
 
pnode dummy = NULL;
 
int get(pnode &root){
    return root ? root->sum : 0;
}
pnode initialize(int value){
    pnode root = (pnode)malloc(sizeof(node));
    root->sum = value;
    root->l = NULL;
    root->r = NULL;
    return root;
}
pnode add(pnode &root, int low, int high, int pos, int value){
    if(!root)
        root = initialize(0);
    if(low == high){
        return initialize(root->sum + value);
    }
    
    int mid = (low + high) >> 1;
    pnode p = initialize(0);
    if(pos <= mid){
        p->l = add(root->l, low, mid, pos, value);
        p->r = root->r;
    }
    else{
        p->l = root->l;
        p->r = add(root->r, mid + 1, high, pos, value);
    }
    p->sum = get(p->l) + get(p->r);
    
    return p;
}
int get(pnode &root, int low, int high, int l, int r){
    if(!root)
        return 0;
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return root->sum;
    
    int mid = (low + high) >> 1;
    return get(root->l, low, mid, l, r)
    + get(root->r, mid + 1, high, l, r);
}
int kth_Element(pnode &root, int low, int high, int k){
    if(low == high)
        return low;
    int mid = (low + high) >> 1;
    if(k <= get(root->l))
        return kth_Element(root->l, low, mid, k);
    else return kth_Element(root->r, mid + 1, high, k - get(root->l));
}
 
template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}
template<class T> void fastPrint(T n){
    if(n == 0){
        puts("0");
        return;
    }
    char buffer[256];
    int ptr = 0, sign = 1;
    
    if(n < 0){
        sign = -1;
        n *= -1;
    }
    while(n > 0){
        buffer[ptr ++] = (char)(n % 10 + '0');
        n /= 10;
    }
    if(sign == -1)
        putchar_unlocked('-');
    for(int i = ptr - 1; i >= 0; i --)
        putchar_unlocked(buffer[i]);
    putchar_unlocked('\n');
}
 
 
int N, Q;
int type, I, L, K;
int a[me];
vector<int> values;
vector<int> positions[me];
pnode roots[me];
 
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    fastInput(N);
    fastInput(Q);
    
    for(int i = 0; i < N; i ++)
        fastInput(a[i]);
    
    values = vector<int>(a, a + N);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    
    for(int i = 0; i < N; i ++)
        a[i] = (int)(lower_bound(values.begin(), values.end(), a[i]) - values.begin()) + 1;
    for(int i = 0; i < N; i ++)
        positions[a[i]].push_back(i);
    
    int MAX = (int)values.size() + 5;
    
    roots[0] = add(dummy, 1, MAX, a[0], 1);
    for(int i = 1; i < N; i ++)
        roots[i] = add(roots[i - 1], 1, MAX, a[i], 1);
    
    while(Q --){
        scanf("%d", &type);
        
        if(type == 0){
            fastInput(I);
            fastInput(L);
            fastInput(K);
            
            int D = kth_Element(roots[I], 1, MAX, K);
            
            if((int)positions[D].size() < L)
                puts("-1");
            else fastPrint(positions[D][L - 1]);
        }
        else{
            fastInput(I);
            
            if(I > N - 2 || a[I] == a[I + 1])
                continue;
        
            int ps1 = (int)(lower_bound(positions[a[I]].begin(), positions[a[I]].end(), I)
                            - positions[a[I]].begin());
            positions[a[I]][ps1] ++;
            int ps2 = (int)(lower_bound(positions[a[I + 1]].begin(), positions[a[I + 1]].end(), I + 1)
                            - positions[a[I + 1]].begin());
            positions[a[I + 1]][ps2] --;
            
            roots[I] = add(roots[I], 1, MAX, a[I], -1);
            swap(a[I], a[I + 1]);
            roots[I] = add(roots[I], 1, MAX, a[I], 1);
        }
    }
    
    return 0;
}