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

const int me = 1000025;

int T, N;
int win[me];

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 1; i < me; i ++){
        for(int j = 1; j * j <= i; j ++){
            if(!win[i - j * j]){
                win[i] = 1;
                break;
            }
        }
    }
    T = uget();
    while(T --){
        N = uget();
        if(win[N])
            puts("Win");
        else puts("Lose");
    }
    
    return 0;
}
