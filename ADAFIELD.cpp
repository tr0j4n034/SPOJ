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

const int me = 100025;

template <class T> void FastInput(T &n){
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

template<class T> void FastPrint(T n){
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

#define ii long long

int T;
int t;
ii n, w, h, ans, v;
multiset<ii>x, y, dif[4];
multiset<ii>::iterator it, it2;
int f;
pair<ii, ii>gx, gy;
ii up, low, X, Y, go;


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    FastInput(T);
    while(T --){
        x.clear();
        y.clear();
        dif[1].clear();
        dif[2].clear();
        scanf("%lld%lld%d", &w, &h, &t);
        
        x.insert(0);
        x.insert(w);
        y.insert(0);
        y.insert(h);
        dif[1].insert(w);
        dif[2].insert(h);
        
        
        for(int W = 1 ; W <= t ; W ++)
        {
            scanf("%d%lld", &f, &v);
            if(f == 0)
            {
                if(x.find(v) == x.end()){
                    x.insert(v);
                    it = x.find(v);
                    it ++;
                    up = *it;
                    it --; it --;
                    low = *it;
                    go = up - low;
                    it2 = dif[1].find(go);
                    dif[1].erase(it2);
                    dif[1].insert(v - low);
                    dif[1].insert(up - v);
                }
            }
            else
            {
                if(y.find(v) == y.end()){
                    y.insert(v);
                    it = y.find(v);
                    it ++;
                    up = *it;
                    it --; it --;
                    low = *it;
                    go = up - low;
                    it2 = dif[2].find(go);
                    dif[2].erase(it2);
                    dif[2].insert(v - low);
                    dif[2].insert(up - v);
                }
            }
            it = dif[1].end();
            it --;
            X = *it;
            it = dif[2].end();
            it --;
            Y = *it;
            printf("%lld\n", X * Y);
        }
        
    }
    
    return 0;
}