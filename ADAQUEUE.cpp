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

const int me = 100025;

int q, x;
bool rev;
char type[10];
deque<int> Q;

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &q);
    while(q --){
        scanf(" %s", type);
        if(type[0] == 't'){
            scanf("%d", &x);
            if(!rev)
                Q.push_front(x);
            else Q.push_back(x);
        }
        else if(type[0] == 'p'){
            scanf("%d", &x);
            if(!rev)
                Q.push_back(x);
            else Q.push_front(x);
        }
        else if(type[0] == 'r'){
            rev ^= 1;
        }
        else if(type[0] == 'b'){
            if(Q.empty())
                puts("No job for Ada?");
            else if(!rev){
                printf("%d\n", Q.back());
                Q.pop_back();
            }
            else{
                printf("%d\n", Q.front());
                Q.pop_front();
            }
        }
        else{
            if(Q.empty())
                puts("No job for Ada?");
            else if(!rev){
                printf("%d\n", Q.front());
                Q.pop_front();
            }
            else{
                printf("%d\n", Q.back());
                Q.pop_back();
            }
        }
    }
    
    return 0;
}
