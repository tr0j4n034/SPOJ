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
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bitset>

using namespace std;

const int me = 500025;

int N;
int a[me], cnt[me];
set<int> notactive;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d", &N);
    for(int i = 0; i < N; i ++)
        scanf("%d", &a[i]);
    for(int i = 0; i < N + 1; i ++)
        notactive.insert(i + 1);
    int result = 0, ptr = 0;
    for(int i = 0; i < N; i ++){
        cnt[a[i]] ++;
        if(notactive.find(a[i]) != notactive.end())
            notactive.erase(a[i]);
        while(cnt[a[i]] > 1){
            cnt[a[ptr]] --;
            if(cnt[a[ptr]] == 0)
                notactive.insert(a[ptr]);
            ptr ++;
        }
        result = max(result, *(notactive.begin()) - 1);
    }
    cout << result << endl;
           
    return 0;
}
