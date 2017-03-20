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

int Q;
int type, x, y;
char ch;
rope<char> r;

int main(){
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);

  while(ch = getchar_unlocked(), ch != '\n'){
    r.push_back(ch);
  }

  fastInput(Q);
  while(Q --){
    fastInput(type);
    if(type == 3){
      fastInput(x);
      putchar_unlocked(r[x]);
      putchar_unlocked('\n');
    }
    else{
      fastInput(x);
      fastInput(y);

      if(x > y)
        swap(x, y);
      rope<char> s = r.substr(x, y - x + 1);
      r.erase(x, y - x + 1);
      if(type == 1){
        r.insert(r.mutable_begin(), s);
      }
      else{
        r.insert(r.mutable_end(), s);
      }
    }
  }

  return 0;  
}
