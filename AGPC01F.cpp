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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bitset>

using namespace std;

const int me = 100025;

int T, N, Q;
int a[me], result[me];
pair<int, int> queries[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &N, &Q);
        for(int i = 0; i < N; i ++)
            scanf("%d", &a[i]);
        for(int i = 0; i < Q; i ++){
            scanf("%d", &queries[i].first);
            queries[i].second = i;
        }
        sort(queries, queries + Q);
        int ptr = 0, smallest = a[0];
        for(int i = 0; i < N; i ++){
            smallest = min(smallest, a[i]);
            while(ptr < Q && queries[ptr].first <= i + 1){
                result[queries[ptr].second] = smallest;
                ptr ++;
            }
        }
        for(int i = 0; i < Q; i ++)
            printf("%d\n", result[i]);
        putchar('\n');
    }
    
    return 0;
}
