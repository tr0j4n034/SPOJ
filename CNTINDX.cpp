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

const int me = 100000025;

int q, sz, type, x, l, r;
vector<int> a;
vector<int> v[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &q);
    while(q --){
        scanf("%d", &type);
        if(type == 0){
            if(sz == 0){
                printf("invalid\n");
                continue;
            }
            int x = a.back();
            a.pop_back();
            v[x].pop_back();
            sz --;
        }
        else if(type == 1){
            scanf("%d", &x);
            a.push_back(x);
            v[x].push_back(++sz);
        }
        else{
            scanf("%d%d%d", &x, &l, &r);
            printf("%d\n", (int)(upper_bound(v[x].begin(), v[x].end(), r)
                                 - upper_bound(v[x].begin(), v[x].end(), l - 1)));
        }
    }
    
    return 0;
}
