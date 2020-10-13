#include<bits/stdc++.h>
 
#include<string>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl "\n"
 
int main() {
  ll t, i, j;
  cin >> t;
  while (t--) {
    ll counter = 0, p = 0, q = 0,c=0;
    string s;
    cin >> s;
    s.erase(0, min(s.find_first_not_of('0'), s.size()-1));
 
    if (s.length() == 1 && s != "9") {
      if (s == "1")
        cout << "2" << endl;
      else if (s == "2")
        cout << "3" << endl;
      else if (s == "3")
        cout << "4" << endl;
      else if (s == "4")
        cout << "5" << endl;
      else if (s == "5")
        cout << "6" << endl;
      else if (s == "6")
        cout << "7" << endl;
      else if (s == "7")
        cout << "8" << endl;
      else if (s == "8")
        cout << "9" << endl;
      else if (s == "0")
        cout << "1" << endl;
 
      continue;
    }
    for (i = 0; i < s.length(); i++) {
      if (s[i] == '9')
        counter++;
    }
    if (counter == s.length()) {
      cout << stoi(s) + 2 << endl;
      continue;
    }
    string  y = s;
    for (i = 0, j = s.length() - 1; i < j; i++, j--) {
      if (s[i] == s[j])
        continue;
      else if (s[i] != s[j]) {
        s[j] = s[i];
      }
    }
    string x = s;
    if (x < y || x==y) {
      if (s.length() % 2 == 0) {
        ll m = s.length() / 2;
        p = m;
        q = m - 1;
        if (s[p] == '9' && s[q] == '9') {
          while (s[p] == '9' && s[q] == '9') {
            s[p] = '0';
            s[q] = '0';
            p++;
            q--;
          }
          s[p] += 1;
          s[q] += 1;
 
          cout << s << endl;
          continue;
        }
        s[m-1] = s[m-1] + 1;
        s[m] = s[m-1];
      }
      else {
        int m = (s.length() - 1) / 2;
 
        if (s[m] == '9') {
          s[m] = '0';
          p = m - 1;
          q = m + 1;
          if (s[p] == '9' && s[q] == '9') {
            while (s[p] == '9' && s[q] == '9') {
              s[p] = '0';
              s[q] = '0';
              p--;
              q++;
 
            }
            s[p] += 1;
            s[q] += 1;
 
            cout << s << endl;
            continue;
          }
        }
 
        s[m] = s[m] + 1;
      }
 
    }
    cout << s << endl;
 
  }
}