#include <bits/stdc++.h>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_cxx;
 
template <class T> T fastInput(T &N){
  char ch;
 
  while(ch = getchar(), isspace(ch));
  N = 0;
  int sign = 1;
  if(ch == '-')
    sign = -1;
  else N = ch - '0';
 
  while(ch = getchar(), isdigit(ch)){
    N = (N << 3) + (N << 1) + ch - '0';
  }
  if(sign == -1)
    N = ~N + 1;
  return N;
}
 
const int me = 10005;
 
int Q;
int type, x, y;
char ch;
rope<char> r[10005];
 
int main(){
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
 
  while(ch = getchar_unlocked(), ch != '\n'){
    r[0].push_back(ch);
  }
 
  fastInput(Q);
  for(int i = 1; i <= Q; i ++){
    fastInput(type);
    if(type == 3){
      fastInput(x);
      putchar_unlocked(r[i - 1][x]);
      putchar_unlocked('\n');
      r[i] = r[i - 1];
    }
    else if(type == 4){
    	fastInput(x);
    	fastInput(y);
    	putchar_unlocked(r[x][y]);
    	putchar_unlocked('\n');
    	r[i] = r[i - 1];
    }
    else{
      fastInput(x);
      fastInput(y);
 
      if(x > y)
        swap(x, y);
      r[i] = (rope<char>)r[i - 1];
      rope<char> s = r[i].substr(x, y - x + 1);
      r[i].erase(x, y - x + 1);
      if(type == 1){
        r[i].insert(r[i].mutable_begin(), s);
      }
      else{
        r[i].insert(r[i].mutable_end(), s);
      }
    }
  }
 
  return 0;
}