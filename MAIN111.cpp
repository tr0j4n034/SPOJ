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

const int me = 100025;

int T, A, B;
int p[me], s[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    p[0] = p[1] = 1;
    for(int i = 2; i < me; i ++)
        if(!p[i])
            for(int j = i + i; j < me; j += i)
                p[j] = 1;
    for(int i = 1; i < me; i ++){
        char buffer[7];
        sprintf(buffer, "%d", i);
        vector<int> digits;
        for(int j = 0; j < 7 && buffer[j] != 0; j ++){
            digits.push_back(buffer[j] - '0');
        }
        int l = (int)digits.size();
        int good = 1;
        for(int j = 1; j < (1 << l); j ++){
            int x = 0;
            for(int k = 0; k < l; k ++)
                if(j & (1 << k))
                    x = 10 * x + digits[k];
            if(!p[x]){
                good = 0;
                break;
            }
        }
        s[i] = s[i - 1] + good;
    }
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &A, &B);
        if(A > B)
            swap(A, B);
        printf("%d\n", s[B] - s[A - 1]);
    }
    
    return 0;
}
