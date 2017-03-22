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

using namespace std;

const int me = 1025;

int T, N;
char ch;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        getchar_unlocked();
        
        map<vector<string>, int> m;
        for(int i = 0; i < N; i ++){
            vector<string> v;
            string s = "";
            while((ch = getchar_unlocked()) != '\n'){
                if(ch == ' '){
                    v.push_back(s);
                    s = "";
                }
                else s += ch;
            }
            if(!s.empty())
                v.push_back(s);
            m[v] ++;
        }
        for(auto i : m){
            for(auto j : i.first)
                printf("%s ", j.c_str());
            printf("%d\n", i.second);
        }
        if(T > 0)
            putchar('\n');
    }
    
    return 0;
}
