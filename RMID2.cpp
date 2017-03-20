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
int x;
multiset<int> small, big;
 
void fix(){
    while((int)small.size() - 1 > (int)big.size()){
        int x = *(--small.end());
        big.insert(x);
        small.erase(small.find(x));
    }
    while((int)small.size() < (int)big.size()){
        int x = *(big.begin());
        small.insert(x);
        big.erase(big.find(x));
    }
    while(!small.empty() && !big.empty() && *(--small.end()) > *(big.begin())){
        int x = *(--small.end());
        int y = *(big.begin());
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
        while(scanf("%d", &x)){
            if(x == 0)
                break;
            if(x > 0){
                small.insert(x);
                fix();
            }
            else{
                x = *(--small.end());
                printf("%d\n", x);
                small.erase(small.find(x));
                fix();
            }
            //for(long long i : small)
            //    cout << i << ", ";
            //cout << endl;
            //for(long long i : big)
            //    cout << i << ", ";
            //cout << endl;
        }
        if(t > 0)
            printf("\n");
    }
    
    return 0;
}