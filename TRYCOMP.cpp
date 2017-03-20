#include <bits/stdc++.h>
 
using namespace std;
 
int N, Q;
unordered_map<string, int> counts;
unordered_map<string, string> result;
 
int main()
{
    scanf("%d", &N);
    getchar_unlocked();
 
    for(int i = 0; i < N; i ++){
        string now = "";
        char ch;
        while(ch = getchar_unlocked(), ch != '\n'){
            now += ch;
        }
        counts[now] ++;
    }
    for(unordered_map<string, int> :: iterator it = counts.begin(); it != counts.end(); it ++){
        string s = (*it).first;
        string now = "";
 
        for(int i = 0; i < (int)s.size(); i ++){
            now.push_back(s[i]);
            if(!result.count(now) || (counts[result[now]] < (*it).second) || (counts[result[now]] == (*it).second && result[now] > s))
                result[now] = s;
        }
    }
 
    scanf("%d", &Q);
    getchar();
 
    while(Q --){
        string now = "";
        char ch;
        while(ch = getchar_unlocked(), ch != '\n'){
            now +=ch;
        }
        if(result.count(now))
            printf("%s %d\n", result[now].c_str(), counts[result[now]]);
        else puts("-1");
    }
 
    return 0;
}
/*
10
apple
banana
orange
applet
banana
oriental
orange
oriental
applet
bangalore
8
ban
bang
app
or
oriental
apple
hobbits
oranges
*/ 