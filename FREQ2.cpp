//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/30/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 100005;
const int MAGIC = 333;

struct query{
    int l;
    int r;
    int id;
    query() {
        
    }
    query(int l, int r, int id):
    l(l), r(r), id(id) {
        
    }
    bool operator < (const query other) const{
        if(l / MAGIC != other.l / MAGIC) {
            return l / MAGIC < other.l / MAGIC;
        }
        return r < other.r;
    }
};

int N, Q;
int a[MAX], output[MAX], counts[MAX], frequencies[MAX];
vector<query> queries;

void fix(int &answer) {
    while (frequencies[answer + 1] > 0) {
        answer ++;
    }
    while (answer > 0 && frequencies[answer] == 0) {
        answer --;
    }
}
void add(int position, int &answer) {
    frequencies[counts[a[position]]] --;
    counts[a[position]] ++;
    frequencies[counts[a[position]]] ++;
    fix(answer);
}
void remove(int position, int &answer) {
    frequencies[counts[a[position]]] --;
    counts[a[position]] --;
    if (counts[a[position]] > 0) {
        frequencies[counts[a[position]]] ++;
    }
    fix(answer);
}
template <class T> void fastInput(T &n){
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

int main(int argc, const char * argv[]) {
    //scanf("%d%d", &N, &Q);
    fastInput(N);
    fastInput(Q);
    for (int i = 0; i < N; i ++) {
        //scanf("%d", &a[i]);
        fastInput(a[i]);
    }
    for (int i = 0; i < Q; i ++) {
        int l, r;
        //scanf("%d%d", &l, &r);
        fastInput(l);
        fastInput(r);
        queries.push_back(query(l, r, i));
    }
    sort(queries.begin(), queries.end());
    int L = N - 1, R = N - 1;
    int answer = 0;
    for(int i = 0; i < Q; i ++) {
        for(int j = L; j >= queries[i].l; j --) {
            add(j, answer);
        }
        for(int j = R + 1; j <= queries[i].r; j ++) {
            add(j, answer);
        }
        for(int j = L + 1; j < queries[i].l; j ++) {
            remove(j, answer);
        }
        for(int j = R; j > queries[i].r; j --) {
            remove(j, answer);
        }
        L = queries[i].l - 1;
        R = queries[i].r;
        output[queries[i].id] = answer;
    }
    for(int i = 0; i < Q; i ++) {
        printf("%d\n", output[i]);
    }
    
    return 0;
}
