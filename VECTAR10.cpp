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

const int me = 1000025;

int f[me];

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    f[1] = 1;
    for(int i = 2, j = 0; i < me; i ++){
        f[i] = i - j;
        if(j == 0)
            j = i - 1;
        else j --;
    }
    int n;
    while(1){
        n = uget();
        if(n == 0)
            break;
        printf("%d\n", f[n]);
    }
    
    return 0;
}
