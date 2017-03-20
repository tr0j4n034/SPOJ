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

const int me = 100025;

template <class T> void FastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

char ch;

string s[] = {
"# # # # # # # # # # #         # # # # # # # # # # #",
"#    #     ##                    #    #",
"# # #  #   #    #                  # #  #",
"#   #  # #  #      #                 #  # #",
"#     #    #   ######                  #    #",
"#       #    #  #                        #    #",
"#     #    #    #            #     #   #    #",
"#   #    #      #        #  #  #  #  #    #",
"# #    #        #     #     #    # #    #",
"#    #          #  #             #    #"
};

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> ch;
    
    for(int i = 0; i < 10; i ++){
        for(char &j : s[i])
            if(j == '#')
                j = ch;
    }
    for(int i = 0; i < 10; i ++){
        cout << s[i] << endl;
    }
    
    return 0;
}
