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

//int sum[me], cnt[me], ans[me];
//int pw[10][10];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    /*
    for(int i = 1; i < me; i ++){
        cnt[i] = cnt[i / 10] + 1;
    }
    for(int i = 1; i < 10; i ++)
        pw[i][0] = 1;
    for(int i = 1; i < 10; i ++)
        for(int j = 1; j < 10; j ++)
            pw[i][j] = pw[i][j - 1] * i;
    for(int i = 1; i < me; i ++){
        int s = 0;
        int j = i;
        while(j > 0){
            s += pw[j % 10][cnt[i]];
            j /= 10;
        }
        if(i == s)
            ans[cnt[i]] ++;
    }
    for(int i = 1; i < 9; i ++)
        cout << ans[i] << " ";
    cout << endl;
    */
    
    int res[] = {0 ,9 ,0 ,4 ,3, 3, 1, 4, 3};
    int n;
    
    cin >> n;
    cout << res[n] << endl;
    
    return 0;
}
