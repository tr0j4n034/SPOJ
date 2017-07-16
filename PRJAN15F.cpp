//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 16/07/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

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
//#include <unordered_set>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 100025;

struct node{
    int value;
    node * back;
    node(){
        
    }
};
typedef node* pnode;

pnode initialize(int value){
    pnode p = (pnode)malloc(sizeof(node));
    p->value = value;
    p->back = NULL;
    return p;
}
void add(pnode &p, int value){
    pnode item = initialize(value);
    if(!p){
        p = item;
        return;
    }
    item->back = p;
    p = item;
}
int top(pnode &p){
    assert(p);
    return p->value;
}
void pop(pnode &p){
    assert(p);
    p = p->back;
}
void combine(pnode &p, pnode &q){
    if(!q){
        return;
    }
    if(!p){
        p = q;
        q = NULL;
        return;
    }
    pnode current = q;
    while(current && current->back){
        current = current->back;
    }
    current->back = p;
    p = q;
    q = NULL;
}
void print(pnode p){
    while(p){
        cout << p->value << ", ";
        p = p->back;
    }
    cout << endl;
}

int T, N, Q;
pnode s[me];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int c = 0; c < T; c ++){
        for(int i = 1; i < me; i ++){
            s[i] = NULL;
        }
        cin >> N >> Q;
        cout << "Case " << c + 1 << ":" << endl;
        while(Q --){
            string type;
            int id, x;
            cin >> type;
            if(type == "push"){
                cin >> id >> x;
                add(s[id], x);
            }
            else if(type == "pop"){
                cin >> id;
                if(s[id]){
                    pop(s[id]);
                }
            }
            else if(type == "put"){
                cin >> id >> x;
                if(id == x){
                    continue;
                }
                combine(s[id], s[x]);
            }
            else{
                cin >> id;
                if(!s[id]){
                    cout << "Empty!" << endl;
                }
                else{
                    cout << top(s[id]) << endl;
                }
            }
        }
    }
    
    return 0;
}
