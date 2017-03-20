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

const int me = 125;

int T;
char ch, x, y;
int in[me], low[me], high[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 'A'; i <= 'Z'; i ++){
        low[i] = 1 << 30;
        high[i] = -1;
    }
    for(int i = 1; (ch = getchar()) != '\n'; i ++){
        if(!in[ch]){
            in[ch] = 1;
            low[ch] = i;
            high[ch] = i;
        }
        else{
            high[ch] = i;
        }
    }
    
    scanf("%d", &T);
    while(T --){
        scanf(" %c %c", &x, &y);
        if(low[x] < high[y])
            puts("YA");
        else puts("TIDAK");
    }
    
    return 0;
}
