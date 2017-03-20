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

int t, l, r;
long long m;
long long fib[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    
    
    scanf("%d", &t);
    while(t --){
        scanf("%d%d%lld", &l, &r, &m);
        fib[1] = 1 % m;
        fib[2] = 1 % m;
        for(int i = 2; i <= r; i ++)
            fib[i] = (fib[i - 1] + fib[i - 2]) % m;
        int s = 0;
        for(int i = l; i <= r; i ++)
            if(fib[i] == 0)
                s ++;
        printf("%d\n", s);
    }
    
    return 0;
}
