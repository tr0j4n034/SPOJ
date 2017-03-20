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

const int me = 51;

#define f(i, a, b) for(int i = a; i <= b; i ++)

int n;
int cubes[me];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    f(i, 1, me - 1)
        cubes[i] = i * i * i;
    
    cin >> n;
    int ans = 0;
    f(i, 1, me - 1){
        if(cubes[i] > n)
            break;
        if(cubes[i] == n)
            ans ++;
        f(j, i, me - 1){
            if(cubes[i] + cubes[j] > n)
                break;
            if(cubes[i] + cubes[j] == n)
                ans ++;
            f(k, j, me - 1){
                if(cubes[i] + cubes[j] + cubes[k] > n)
                    break;
                if(cubes[i] + cubes[j] + cubes[k] == n)
                    ans ++;
                f(q, k, me - 1){
                    if(cubes[i] + cubes[j] + cubes[k] + cubes[q] > n)
                        break;
                    if(cubes[i] + cubes[j] + cubes[k] + cubes[q] == n)
                        ans ++;
                    f(l, q, me - 1){
                        if(cubes[i] + cubes[j] + cubes[k] + cubes[q] + cubes[l] > n)
                            break;
                        if(cubes[i] + cubes[j] + cubes[k] + cubes[q] + cubes[l] == n){
                            ans ++;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}