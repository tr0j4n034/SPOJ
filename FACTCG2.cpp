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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const long long me = 10000025;

int n;
int sp[me];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!sp[i]){
            for(int j = i; j < me; j += i)
                if(!sp[j])
                    sp[j] = i;
        }
    while(scanf("%d", &n) != EOF){
        printf("1");
        while(n > 1){
            printf(" x %d", sp[n]);
            n /= sp[n];
        }
        puts("");
    }
    
    return 0;
}