//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/18/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O((N + Q) * sqrt(N) * log(N)) solution using MO's algoritm
 Gets time limit exceeded verdict...
 MAX test may run in ~5 seconds. Probably, this solution can not be fastened further.
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 200005;
const int MAGIC = 444;

struct query{
    int id;
    int l;
    int r;
    query() {
        
    }
    query(int _id, int _l, int _r):
    id(_id), l(_l), r(_r) {
        
    }
    bool operator < (const query other) const{
        if (l / MAGIC != other.l / MAGIC) return l / MAGIC < other.l / MAGIC;
        return r < other.r;
    }
};

int N, Q;
int data[MAX];
query queries[MAX];

int activeElements;
long long answer = 0;
int elementCount[MAX];
long long result[MAX];
vector<int> activeCounts;

void add(int position) {
    if (position < 1 || position > N) return;
    //cout << "adding: " << position << endl;
    elementCount[data[position]] ++;
    //cout << "element count is --> " << elementCount[data[position]] << endl;
    if (elementCount[data[position]] == 1) {
        //activeCounts.push_back(1);
        activeCounts[activeElements] = 1;
        activeElements ++;
        answer += activeElements;
    }
    else {
        auto it = lower_bound(activeCounts.begin(), activeCounts.end(), elementCount[data[position]] - 1, greater<int>());
        (*it) ++;
        answer += (int)(it - activeCounts.begin() + 1);
    }
    //cout << "after adding: "; for (int j : activeCounts) cout << j << ", "; cout << " ---> " << answer << endl;
}
void remove(int position) {
    if (position < 1 || position > N) return;
    //cout << "removing: " << position << endl;
    elementCount[data[position]] --;
    if (!elementCount[data[position]]) {
        activeCounts[activeElements - 1] = 0;
        //activeCounts.pop_back();
        answer -= activeElements;
        activeElements --;
    }
    else {
        auto it = --lower_bound(activeCounts.begin(), activeCounts.end(), elementCount[data[position]], greater<int>());
        (*it) --;
        answer -= (int)(it - activeCounts.begin() + 1);
    }
    //cout << "after removing: "; for (int j : activeCounts) cout << j << ", "; cout << " ---> " << answer << endl;
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
template<class T> void fastPrint(T n){
    if(n == 0){
        puts("0");
        return;
    }
    char buffer[256];
    int ptr = 0, sign = 1;
    
    if(n < 0){
        sign = -1;
        n *= -1;
    }
    while(n > 0){
        buffer[ptr ++] = (char)(n % 10 + '0');
        n /= 10;
    }
    if(sign == -1)
        putchar_unlocked('-');
    for(int i = ptr - 1; i >= 0; i --)
        putchar_unlocked(buffer[i]);
    putchar_unlocked('\n');
}

void test() {
    vector<int> v = {5, 2, 1, 1};
    auto it = lower_bound(v.begin(), v.end(), 1, greater<int>());
    (*it) ++;
    cout << *it << " vs " << (int)(it - v.begin()) << endl;
    cout << "now vector is: ";
    for (int i : v) cout << i << ", "; cout << endl;
}
int main() {
    
    //test();
    //return 0;
    
    //scanf("%d%d", &N, &Q);
    fastInput(N);
    fastInput(Q);
    for (int i = 1; i <= N; i ++) {
        //scanf("%d", &data[i]);
        fastInput(data[i]);
    }
    vector<int> keys = vector<int>(data + 1, data + N + 1);
    sort(keys.begin(), keys.end());
    keys.erase(unique(keys.begin(), keys.end()), keys.end());
    for (int i = 1; i <= N; i ++) {
        data[i] = (int)(lower_bound(keys.begin(), keys.end(), data[i]) - keys.begin()) + 1;
    }
    int l = (int)keys.size();
    //for (int i = 1; i <= N; i ++) cout << data[i] << ", ";
    //cout << endl;
    //cout << endl;
    for (int i = 0; i < Q; i ++) {
        int l, r;
        //scanf("%d%d", &l, &r);
        fastInput(l);
        fastInput(r);
        queries[i] = query(i, l, r);
    }
    if (l == N) {
        for (int i = 0; i < Q; i ++) {
            int m = queries[i].r - queries[i].l + 1;
            printf("%lld\n", 1LL * m * (m + 1) / 2);
        }
        return 0;
    }
    sort(queries, queries + Q);
    activeCounts.resize(N, 0);
    int L = 1, R = 0;
    for (int i = 0; i < Q; i ++) {
        //cout << "now query comes: " << queries[i].l << " vs " << queries[i].r << endl;
        while (L > queries[i].l) add(--L);
        while (R < queries[i].r) add(++R);
        while (R > queries[i].r) remove(R --);
        while (L < queries[i].l) remove(L ++);
        
        result[queries[i].id] = answer;
        
        //for (int j : activeCounts) cout << j << ", "; cout << endl;
    }
    for (int i = 0; i < Q; i ++) {
        //printf("%d\n", result[i]);
        fastPrint(result[i]);
    }
    
    return 0;
}
