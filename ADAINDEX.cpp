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
    if(sign == -1)
        n = ~n + 1;
}
template<class T> void FastPrint(T n){
    if(n == 0){
        puts("0");
        return;
    }
    char buffer[256];
    int ptr = 0, sign = 1;
    
    if(n < 0){
        sign = -1;
        n = ~n + 1;
    }
    while(n > 0){
        buffer[ptr ++] = (char)(n % 10 + '0');
        n /= 10;
    }
    if(sign == -1)
        putchar_unlocked('-');
    for(int i = ptr - 1; i >= 0; i --)
        putchar_unlocked(buffer[i]);
    puts("");
}

const int ALPHABET = 26;
const char LOW = 'a';

struct node{
    int count;
    node *links[ALPHABET];
    
    node() {
        count = 0;
    }
};

typedef node* pnode;

pnode Initialize(int value){
    pnode item = (pnode)malloc(sizeof(node));
    item->count = value;
    for(int i = 0; i < ALPHABET; i ++)
        item->links[i] = NULL;
    return item;
}
void add(pnode &root, char *s, int length){
    pnode now = root;
    for(int i = 0; i < length; i ++){
        int position = s[i] - LOW;
        if(now->links[position] == NULL){
            now->links[position] = Initialize(0);
        }
        now = now->links[position];
        now->count ++;
    }
}
int get(pnode &root, char *s, int length){
    pnode now = root;
    for(int i = 0; i < length; i ++){
        int position = s[i] - LOW;
        if(now->links[position] == NULL)
            return 0;
        now = now->links[position];
    }
    return now->count;
}

int N, Q;
char s[me];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    pnode root = Initialize(0);
    
    scanf("%d%d", &N, &Q);
    getchar();
    
    while(N --){
        int length = 0;
        char ch;
        while(ch = getchar(), ch != '\n')
            s[length ++] = ch;
        add(root, s, length);
    }
    while(Q --){
        int length = 0;
        char ch;
        while(ch = getchar(), ch != '\n')
            s[length ++] = ch;
        printf("%d\n", get(root, s, length));
    }
    
    return 0;
}
