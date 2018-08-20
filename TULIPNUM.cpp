//
//  main.cpp
//  practice
//
//  Created by Mahmud on 20/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

// simple O(T * (N * log(N) + Q)) solution using prefix sums

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int S = 1 << 18;


int T, N, Q;
int data[S], sum[S];

template <class T>
void fastInput(T &N) {
    char ch;
    int sign = 1;
    N = 0;
    while ((ch = getchar_unlocked()) && ch == ' ') {};
    if (ch == '-') sign = -1;
    else if (isdigit(ch)) N = ch - '0';
    while ((ch = getchar_unlocked()) && isdigit(ch)) {
        N = (N << 1) + (N << 3) + ch - '0';
    }
    if (sign == -1) N = ~N + 1;
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

int main() {
    //scanf("%d", &T);
    fastInput(T);
    for (int c = 0; c < T; c ++) {
        //scanf("%d%d", &N, &Q);
        fastInput(N);
        fastInput(Q);
        for (int i = 1; i <= N; i ++) {
            //scanf("%d", &data[i]);
            fastInput(data[i]);
        }
        vector<int> values = vector<int>(data + 1, data + N + 1);
        sort(values.begin(), values.end());
        for (int i = 1; i <= N; i ++) {
            data[i] = (int)(lower_bound(values.begin(), values.end(), data[i]) - values.begin()) + 1;
            sum[i] = 0;
        }
        for (int i = 1; i <= N; i ++) {
            sum[data[i]] = 1;
        }
        for (int i = 1; i <= N; i ++) {
            sum[i] += sum[i - 1];
        }
        printf("Case %d:\n", c + 1);
        while (Q --) {
            int l, r;
            //scanf("%d%d", &l, &r);
            fastInput(l);
            fastInput(r);
            //printf("%d\n", get(roots[r], 1, N + 1, r + 1, N + 1) - get(roots[l - 1], 1, N + 1, r + 1, N + 1));
            fastPrint(sum[data[r]] - sum[data[l] - 1]);
        }
    }
    
    return 0;
}

