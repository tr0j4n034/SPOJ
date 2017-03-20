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

const int me = 10025;

//vector<int> good;
//int used[me];
int bad[] = {1, 2, 3, 5, 6, 7, 10, 11, 14, 15, 19, 23};

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    /*
    for(int i = 2; i < 300; i ++)
        good.push_back(i * i);
    for(int i = 2; i < 101; i ++)
        good.push_back(i * i * i);
    for(int i = 2; i < 60; i ++)
        good.push_back(i * i * i * i * i);
    for(int i = 2; i < 10; i ++)
        good.push_back(i * i * i * i * i * i * i);
    
    used[0] = 1;
    for(int i = 1; i < me; i ++)
        for(int j : good)
            if(i >= j && used[i - j])
                used[i] = 1;
    for(int i = 1; i < me; i ++)
        if(!used[i])
            cout << i << endl;
    // only numbers in bad[] can not be represented as sum of powers :D
    */
    
    int T;
    long long A, B;
    
    scanf("%d", &T);
    while(T --){
        scanf("%lld%lld", &A, &B);
        assert(A <= B);
        int s = 0;
        for(int i = 0; i < 12; i ++)
            if(bad[i] >= A && bad[i] <= B)
                s ++;
        printf("%lld\n", B - A + 1 - s);
    }
    
    return 0;
}
