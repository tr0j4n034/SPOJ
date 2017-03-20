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
    puts("");
}

const int me = 100025;

struct myset{
    set<long long> s;
    long long lazy;
    myset(){
        s.clear();
        lazy = 0;
    }
    myset(long long x){
        s.insert(x);
        lazy = 0;
    }
    void update(){
        if(lazy != 0){
            set<long long> t;
            for(auto i : s)
                t.insert(i + lazy);
            lazy = 0;
            s = t;
        }
    }
};
void merge(myset &a, myset &b, long long delta){
    if((int)a.s.size() < (int)b.s.size()){
        //a.update();
        //b.lazy += delta;
        //b.update();
        //for(int i : a.s)
        //    b.s.insert(i);
        b.lazy += delta;
        for(auto i : a.s)
            b.s.insert(i - b.lazy + a.lazy);
        swap(a, b);
    }
    else{
        //a.update();
        b.lazy += delta;
        for(auto i : b.s)
            a.s.insert(i + b.lazy - a.lazy);
        //b.s.clear();
    }
}

int N;
int root;
long long joy[me], change[me], result[me];
myset s[me];
vector<int> edges[me];

void dfs(int node, int parent){
    s[node] = myset(joy[node]);
    for(int i : edges[node]){
        if(i == parent)
            continue;
        dfs(i, node);
        merge(s[node], s[i], change[i]);
    }
    //cout << "node = " << node << " ---> ";
    //for(auto i : s[node].s)
    //cout << i << ", "; cout << "] and lazy = " << s[node].lazy << endl;
    result[node] = (int)s[node].s.size();
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    //fastInput(N);
    scanf("%d", &N);
    for(int i = 1; i <= N; i ++){
        //fastInput(joy[i]);
        scanf("%lld", &joy[i]);
    }
    for(int i = 1; i <= N; i ++){
        int parent;
        //fastInput(parent);
        scanf("%d", &parent);
        edges[parent].push_back(i);
        if(parent == 0)
            root = i;
    }
    for(int i = 1; i <= N; i ++){
        //fastInput(change[i]);
        scanf("%lld", &change[i]);
    }
    dfs(root, -1);
    
    //for(int i = 1; i <= N; i ++)
    //    fastPrint(result[i]);
    
    for(int i = 1; i <= N; i ++)
        printf("%lld\n", result[i]);
    
    return 0;
}
