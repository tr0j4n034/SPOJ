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
#include <list>
//#include <unordered_map>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 1000025;

int N;
int a[me], cnt[me], s[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%d", &a[i]);
        cnt[a[i]] ++;
    }
    for(int i = 1; i < me; i ++)
        if(cnt[i] > 0)
            for(int j = i; j < me; j += i)
                s[j] += cnt[i];
    for(int i = 0; i < N; i ++){
        printf("%d\n", s[a[i]] - 1);
    }
    
    return 0;
}
