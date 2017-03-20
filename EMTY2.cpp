#include<iostream>
#include <list>
#include <stack>
#include <vector>
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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 10025;

int t;
char ch;

bool can(stack<char> &s){
    if((int)s.size() < 2)
        return false;
    char last = s.top();
    if(last == '1')
        return false;
    s.pop();
    char before_last = s.top();
    s.push(last);
    return before_last == '1';
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    getchar();
    for(int c = 0; c < t; c ++){
        stack<char> s;
        while((ch = getchar()) != '\n'){
            if(ch == '0' && can(s)){
                s.pop();
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
        printf("Case %d: ", c + 1);
        puts(s.empty() ? "yes" : "no");
    }
    
    return 0;
}

