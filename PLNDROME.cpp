//
//  main.cpp
//  practice
//
//  Created by Mahmud on 8/2/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <iostream>

using namespace std;

int tests;
int N, Q;
char text[100005];

int main(int argc, const char * argv[]) {
    scanf("%d", &tests);
    for (int c = 0; c < tests; c ++) {
        scanf("%d", &N);
        scanf(" %s", text);
        scanf("%d", &Q);
        
        int differences = 0;
        for (int i = 0; i + i < N; i ++) {
            if (text[i] != text[N - 1 - i]) {
                differences ++;
            }
        }
        printf("Case %d:\n", c + 1);
        while (Q --) {
            int position;
            char ch;
            scanf("%d %c", &position, &ch);
            --position;
            if (text[position] == text[N - 1 - position] && position != N - 1 - position && text[position] != ch) {
                differences ++;
            }
            else if (text[position] != text[N - 1 - position] && text[N - 1 - position] == ch) {
                differences --;
            }
            text[position] = ch;
            if (differences == 0) {
                puts("YES");
            }
            else {
                puts("NO");
            }
        }
    }
    
    return 0;
}
