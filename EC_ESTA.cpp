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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1005;

int t;
long long x;
multiset<long long> small, big;

void fix(){
    while((int)small.size() - 1 > (int)big.size()){
        long long x = *(--small.end());
        big.insert(x);
        small.erase(small.find(x));
    }
    while((int)small.size() < (int)big.size()){
        long long x = *(big.begin());
        small.insert(x);
        big.erase(big.find(x));
    }
    while(!small.empty() && !big.empty() && *(--small.end()) > *(big.begin())){
        long long x = *(--small.end());
        long long y = *(big.begin());
        small.erase(small.find(x));
        big.insert(x);
        big.erase(big.find(y));
        small.insert(y);
    }
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        small.clear();
        big.clear();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            scanf("%lld", &x);
            small.insert(x);
            fix();
            if(i & 1){
                long long l = *(--small.end());
                long long r = *(big.begin());
                long long sum = l + r;
                if(sum & 1)
                    printf("%lld.5\n", sum / 2);
                else printf("%lld\n", sum / 2);
            }
            else printf("%lld\n", *(--small.end()));
        }
    }
    
    return 0;
}