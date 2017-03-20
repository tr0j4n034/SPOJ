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
const int ALPHA = 26;
const int LENGTH = 5;

struct node{
    set<char> endings;
    node *child[ALPHA];
    node(){
        endings.clear();
    }
};
typedef node* pnode;

pnode Init(){
    pnode p = (pnode)malloc(sizeof(node));
    p->endings.clear();
    for(int i = 0; i < ALPHA; i ++)
        p->child[i] = NULL;
    return p;
}
void add(pnode &p, char *s, char ch){
    pnode current = p;
    for(int i = 0; i < LENGTH; i ++){
        int x = s[i] - 'a';
        if(!current->child[x]){
            current->child[x] = Init();
        }
        current = current->child[x];
    }
    current->endings.insert(ch);
}
char get(pnode &p, char *s, char not_allowed){
    pnode current = p;
    if(!current)
        return -1;
    for(int i = 0; i < LENGTH; i ++){
        int x = s[i] - 'a';
        if(!current->child[x])
            return -1;
        current = current->child[x];
    }
    for(auto ch : current->endings)
        if(ch != not_allowed)
            return ch;
    return -1;
}
string add(char* s, int pos, char ch){
    string res = "";
    for(int i = 0, j = 0; i < LENGTH + 1; i ++){
        if(i == pos)
            res.push_back(ch);
        else res.push_back(s[j ++]);
    }
    return res;
}

int t, n;
char type;
char v[LENGTH];
string s;
pnode roots[LENGTH + 1];

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 0; i < LENGTH + 1; i ++)
        roots[i] = NULL;
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n;
        for(int i = 0; i < LENGTH + 1; i ++){
            roots[i] = Init();
        }
        printf("Test %d\n", c + 1);
        while(n --){
            cin >> type;
            cin >> s;
            if(type == 'W'){
                for(int i = 0; i < LENGTH + 1; i ++){
                    for(int j = 0, k = 0; k < LENGTH + 1; k ++){
                        if(i == k){
                            continue;
                        }
                        v[j ++] = s[k];
                    }
                    add(roots[i], v, s[i]);
                    //cout << "added i = " << i << ", v = " << v << endl;
                }
            }
            else{
                string ans = "0";
                int found = -1;
                for(int i = 0; i < LENGTH + 1; i ++){
                    for(int j = 0, k = 0; k < LENGTH + 1; k ++){
                        if(i == k){
                            continue;
                        }
                        v[j ++] = s[k];
                    }
                    //cout << "asked i = " << i << ", v = " << v << endl;
                    char x = get(roots[i], v, s[i]);
                    if(x == -1)
                        continue;
                    string go = add(v, i, x);
                    if(found == -1 || go < ans){
                        ans = go;
                        found = 1;
                    }
                }
                cout << ans << endl;
            }
        }
    }
    
    return 0;
}